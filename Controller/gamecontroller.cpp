#include "gamecontroller.h"


GameController::GameController(QObject* parent, QPushButton* pb_endTurn, QLabel* showInfo)
    : QObject(parent)
    , m_queue(new UnitQueue())
    , m_active_unit(nullptr)
    , m_grid(nullptr)
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
}


void GameController::endTurn()
{
    std::cerr << "Game Controller endTurn() called!" << std::endl;
    m_active_unit = m_queue->next();
    emit changeInfo("Turn ended!");
    //TODO: update unit queue list in the UI.
}
