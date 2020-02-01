#include "gamecontroller.h"

#define ACTIVE_UNIT_COLOR Qt::yellow

GameController::GameController(ui ui)
    : QObject(ui.window)
    , m_queue(new UnitQueue())
    , m_active_unit(nullptr)
    , m_grid(nullptr)
    , m_turn(0)
    , m_players(new std::vector<Player*>)
    , m_pb_ok(ui.pb_ok)
    , m_pb_cancel(ui.pb_cancel)
    , m_infoLabel(ui.showInfo)
    , m_scene(ui.scene)
{
    //TODO: check ui for nullptrs
    // create an error(check) method in the ui struct
    // if (ui.error) ...
    for (auto button: ui.actionButtons)
    {
        add_pb_Action(button);
    }

    QObject::connect(ui.pb_ok, SIGNAL(clicked()), this, SLOT(ok()));
    QObject::connect(ui.pb_cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    QObject::connect(ui.pb_endTurn, SIGNAL(clicked()), this, SLOT(endTurn()));
    QObject::connect(this, SIGNAL(changeInfo(const QString&)), ui.showInfo, SLOT(setText(const QString &)));
    QObject::connect(this, SIGNAL(changeInfoPlayer(const QString&)), ui.playerLabel, SLOT(setText(const QString &)));
}


GameController::~GameController()
{
    delete m_queue;
    for (auto player : *m_players)
    {
        delete player;
    }
    delete m_players;
    delete m_ActionClosure;
    //delete m_scene; //?
}


void GameController::setGrid(Grid* grid)
{
    if (!grid) {
        return;
    }
    grid->setPos(0, 0);
    m_scene->addItem(grid);
    m_grid = grid;
    if (grid->signaler()) {
        QObject::connect(grid->signaler(), SIGNAL(fieldLeftClickSignal(position_t)), this, SLOT(fieldLeftClicked(position_t)) );
    }
}


Field* GameController::at(position_t position) const
{
    if (!m_grid) {
        return nullptr;
    }
    return m_grid->at(position);
}


bool GameController::addUnit(Unit* u)
{
    if (!u || !m_grid)
    {
        return false;
    }
    auto field = u->position();
    if (m_grid->placeUnit(field, u))
    {
        m_queue->push_back(u);
        u->setParentItem(at(field));
        return true;
    }
    return false;
}


Unit* GameController::activeUnit() const
{
    return m_active_unit;
}


void GameController::startGame()
{
    m_active_unit = m_queue->current();
    if (!m_active_unit) {
        noActiveUnitError();
    }
    m_active_unit->changeColor(ACTIVE_UNIT_COLOR);
    setInfo(defaultInfo());
    updatePlayer();
    resetActions();
}


QString GameController::getInfo()
{
    return m_infoLabel->text();
}


void GameController::ok()
{
    if (!m_ActionClosure || m_state != action_ready)
    {
        return;
    }
    m_ActionClosure->doAction();
    actionEnd();
}


void GameController::changeState(ControllerState state)
{
    if (state == action_ready)
    {
        m_pb_ok->setEnabled(true);
    }
    else {
        m_pb_ok->setEnabled(false);
    }
    if (state != init)
    {
        m_pb_cancel->setEnabled(true);
    }
    else {
        m_pb_cancel->setEnabled(false);
    }
    m_state = state;
}


void GameController::cancel()
{
    if (m_state != init) {
        actionEnd();
    }
    else {
        setInfo(defaultInfo());
    }
}


void GameController::endTurn()
{
    if (!m_active_unit) {
        noActiveUnitError();
    }
    if (m_state != ControllerState::init) {
        actionEnd();
    }
    m_turn++;
    m_active_unit->changeColor();
    m_active_unit->update();
    m_active_unit = m_queue->next();
    m_active_unit->changeColor(ACTIVE_UNIT_COLOR);
    m_active_unit->update();
    setInfo(defaultInfo());
    updatePlayer();
    resetActions();
    //TODO: update unit queue list in the UI.
}


void GameController::resetActions()
{
    if (!m_active_unit)
    {
        noActiveUnitError();
    }
    auto newActions = m_active_unit->getActions();
    if (!newActions)
    {
        std::cerr << "No actions for unit ";
    }
    emit resetActionsOnButtons(newActions);
}


void GameController::setInfo(std::string msg)
{
    emit changeInfo(msg.c_str());
}


void GameController::add_pb_Action(ActionButton* pb_action)
{
    QObject::connect(pb_action, SIGNAL(actionUsed(Action*)), this, SLOT(actionButtonPressed(Action*)) );
    QObject::connect(this, SIGNAL(resetActionsOnButtons(std::vector<Action*>*)), pb_action, SLOT(setActionsOnButtons(std::vector<Action*>*)));
}


void GameController::actionButtonPressed(Action* action)
{
    if (m_state != ControllerState::init) {
        actionEnd();
    }

    if (action) {
        actionStart(action);
        return;
    } else {
        // This shouldn't happen.
        setInfo("Invalid action!");
    }
}


void GameController::actionStart(Action* action)
{
    if (!action) {
        return;
    }
    if (action->cost() > m_active_unit->AP_left()) {
        setInfo("Not enough AP left!");
        //TODO: show default info. New button?
        return;
    }
    setInfo("Action " + action->name() + " activated "); //TODO: activeActionInfo() -> std::string
    changeState(action_waiting_input);
    m_ActionClosure = new ActionClosure(*action, m_grid, m_queue);
    if (m_ActionClosure->fieldsToAdd() == 0) {
        changeState(action_ready);
    }
}


void GameController::actionEnd()
{
    if (m_ActionClosure) {
        delete m_ActionClosure;
        m_ActionClosure = nullptr;
    }
    setInfo(defaultInfo());
    changeState(init);
}


std::string GameController::defaultInfo() const
{
    auto unit = activeUnit();
    std::string unitInfo = unit
              ? "Active unit is: " + unit->info()
              : "No active unit (Error)";

    return "Turn: " + std::to_string(m_turn)
            + "\n" + unitInfo;
}


std::string GameController::fieldInfo(Field* field) const
{
    return field->info();
}


void GameController::addPlayer(Player* player)
{
    if (player)
    {
        m_players->push_back(player);
    }
}


void GameController::updatePlayer()
{
    if (!m_active_unit) {
        noActiveUnitError();
    }
    Player* player = m_active_unit->player();
    QString name;
    if (player) {
        name = player->name().c_str();
    } else {
        name = "No player!";
        //TODO: No player error?
    }
    emit changeInfoPlayer(name);
}


void GameController::fieldLeftClicked(position_t position)
{
    if (!m_grid) {
        return;
    }
    Field* field = at(position);
    if (!field) {
        return;
    }

    if (m_state == init)
    {
        setInfo(fieldInfo(field));
        return;
    }

    if ((m_state == action_waiting_input) && m_ActionClosure)
    {
        addFieldToClosure(field);
        setInfo(m_ActionClosure->info());
    }
    std::cerr << *field << std::endl;
}


void GameController::addFieldToClosure(Field* field)
{
    if (!m_ActionClosure) {
        return;
    }
    m_ActionClosure->addField(field);
    if (m_ActionClosure->fieldsToAdd() == 0) {
        changeState(action_ready);
    }
}


[[ noreturn ]] void GameController::noActiveUnitError()
{
    std::cerr << "No active unit!" << std::endl;
    exit(0);
}
