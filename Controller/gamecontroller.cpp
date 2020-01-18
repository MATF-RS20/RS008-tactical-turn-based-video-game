#include "gamecontroller.h"


GameController::GameController(QObject* parent, QPushButton* pb_endTurn, QLabel* showInfo)
    : QObject(parent)
    , m_queue(new UnitQueue())
    , m_active_unit(nullptr)
    , m_grid(nullptr)
    , m_infoLabel(showInfo)
    , m_turn(0)
{
    QObject::connect(pb_endTurn, SIGNAL(clicked()), this, SLOT(endTurn()));
    QObject::connect(this, SIGNAL(changeInfo(const QString&)), showInfo, SLOT(setText(const QString &)));
}


GameController::~GameController()
{
    if (m_queue)
    {
        delete m_queue;
    }
    if (m_grid)
    {
        //TODO: window deletes grid?
        //delete m_grid;
    }
}


void GameController::setGrid(Grid* g)
{
    m_grid = g;
}


bool GameController::addUnit(Unit* u)
{
    m_queue->push_back(u);
    if (m_grid)
    {
        auto field = u->position();
        if (m_grid->placeUnit(field, u))
        {
            std::pair<qreal,qreal> pos = calculatePos(field);
            u->setPos(pos.first, pos.second);
            return true;
        }
    }
    //Grid not set yet (==nullptr), can't set units.
    return false;
}


Unit* GameController::activeUnit()
{
    return m_active_unit;
}


void GameController::startGame()
{
    m_active_unit = m_queue->current();
    setInfo(("Turn: " + std::to_string(m_turn)
             + "\nActive unit is: " + activeUnit()->info()
             ).c_str());
}


QString GameController::getInfo()
{
    return m_infoLabel->text();
}


void GameController::endTurn()
{
    std::cerr << "Game Controller endTurn() called!" << std::endl;
    m_turn++;
    m_active_unit = m_queue->next();
    setInfo("Turn: " + std::to_string(m_turn)
             + "\nActive unit is: " + activeUnit()->info()
             );
    //TODO: update unit queue list in the UI.
}


void GameController::setInfo(std::string msg)
{
    emit changeInfo(msg.c_str());
}


std::pair<qreal, qreal> GameController::calculatePos(unsigned row, unsigned col)
{
    if (m_grid)
    {
        //TODO: grid_left, grid_top?
        return  {row * m_field_width,
                 col * m_field_height};
    }
    else {
        return {0, 0};
    }
}


std::pair<qreal, qreal> GameController::calculatePos(std::pair<int, int> position)
{
    //TODO: cast to unsigned warning?
    return calculatePos(position.first, position.second);
}


bool GameController::moveUnit(Unit* unit, std::pair<int, int> position)
{
    if (!m_grid) {
        return false;
    }

    auto old_position = unit->position();
    if (old_position == position)
    {
        return true;
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
}

void GameController::actionButtonPressed(Action* action)
{
    if (action) {
        setInfo("Action activated: ");
        action->use(); //TODO!
    }
    else {
        setInfo("Invalid action!");
    }
}

void GameController::actionButtonPressed(int button_number)
{
    setInfo("Action pressed: " + std::to_string(button_number));
}
