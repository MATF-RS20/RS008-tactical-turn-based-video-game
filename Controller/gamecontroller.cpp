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
    if(m_grid)
    {
        //TODO
        return m_grid->placeUnit(u->position(), u);
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
    setInfo(("Turn: " + std::to_string(m_turn)
             + "\nActive unit is: " + activeUnit()->info()
             ).c_str());
    //TODO: update unit queue list in the UI.
}


void GameController::setInfo(QString msg)
{
    emit changeInfo(msg);
}
