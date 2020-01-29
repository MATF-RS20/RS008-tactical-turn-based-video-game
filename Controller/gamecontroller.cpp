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
}


void GameController::setGrid(Grid* grid)
{
    if (!grid) {
        return;
    }
    grid->setPos(0, 0);
    m_scene->addItem(grid);
    m_grid = grid;
    QObject::connect(grid->signaler(), SIGNAL(fieldLeftClickSignal(position_t)), this, SLOT(fieldLeftClicked(position_t)) );
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
        //std::pair<qreal,qreal> pos = calculatePos(field);
        //u->setPos(pos.first, pos.second);
        u->setParentItem((*m_grid)[field]);
        //m_scene->addItem(u);
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
    //std::cerr << "Ok pressed!" << std::endl;
    if (!m_ActionClosure || m_state != action_ready)
    {
        return;
    }
    // TODO:
    // do the action...
    m_ActionClosure->doAction();
    std::cerr << "Action done!" << std::endl;
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
    //TODO: state dependant actions (init, action...).
    //if (m_state == init) {}
    if (m_state != init) {
        actionEnd();
    }
    //setInfo(defaultInfo());
}


void GameController::endTurn()
{
    //std::cerr << "Game Controller endTurn() called!" << std::endl;
    if (!m_active_unit) {
        noActiveUnitError(); //TODO
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

    /*if (!m_active_unit)
    {
        //This shouldn't happen. Find an elegant solution.
        std::cerr << "endTurn, m_active_unit = nullptr!???";
    }*/
    //TODO: update unit queue list in the UI.
}


void GameController::resetActions()
{
    if (!m_active_unit)
    {
        //This should not happen.
        return;
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


std::pair<qreal, qreal> GameController::calculatePos(std::pair<unsigned, unsigned> position) const
{

    if (m_grid)
    {
        unsigned row = position.first,
                 col = position.second;

        return  {col * m_grid->field_width(),
                 row * m_grid->field_height()};
    }
    else {
        return {0, 0};
    }
}


bool GameController::moveUnit(Unit* unit, std::pair<unsigned, unsigned> position)
{
    if (!m_grid) {
        return false;
    }

    auto old_position = unit->position();
    if (old_position == position)
    {
        return false;
    }

    if (m_grid->placeUnit(position, unit))
    {
        m_grid->removeUnit(old_position);
        std::pair<qreal,qreal> pos = calculatePos(position);
        unit->setPos(pos.first, pos.second);
        return true;
    }
    else {
        return false;
    }
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
        //TODO: This shouldn't happen (non-action are buttons grayed out). Remove maybe?
        setInfo("Invalid action!");
    }
}


void GameController::actionStart(Action* action)
{
    setInfo("Action " + action->name() + " activated "); //TODO: activeActionInfo() -> std::string
    changeState(action_waiting_input);
    m_ActionClosure = new ActionClosure(action->type(), m_grid, m_active_unit->position(), action->cost());
    if (m_ActionClosure->fieldsToAdd() == 0) {
        changeState(action_ready);
    }
}


void GameController::actionEnd()
{
    //TODO...
    if (m_ActionClosure) {
        delete m_ActionClosure;
        m_ActionClosure = nullptr;
    }
    //TODO: reset colored fields...
    setInfo(defaultInfo());
    changeState(init);
    //TODO
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


void GameController::addPlayer(Player* player)
{
    if (player)
    {
        m_players->push_back(player);
    }
}


void GameController::updatePlayer()
{
    if (!m_active_unit)
    {
        return;
    }
    QString name = m_active_unit->player()->name().c_str();
    emit changeInfoPlayer(name);
}


void GameController::noActiveUnitError()
{
    std::cerr << "No active unit! TODO: Protect yourself from this!" << std::endl;
}


void GameController::fieldLeftClicked(position_t position)
{
    if (!m_grid) {
        return;
    }
    Field* field = (*m_grid)[position];
    if (!field)
        return;
    if ((m_state == action_waiting_input) && m_ActionClosure)
    {
        //TODO: print msg to info label
        addFieldToClosure(field); //TODO: field or position?
    }
    std::cerr << *field << std::endl;
    //setInfo("FIELD CLICKED TODO!!!");
}


void GameController::addFieldToClosure(Field* field)
{
    m_ActionClosure->addField(field);
    if (m_ActionClosure->fieldsToAdd() == 0) {
        changeState(action_ready);
    }
}
