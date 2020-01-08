#include "gamecontroller.h"

GameController::GameController()
    :m_queue(new UnitQueue()),
      m_active_unit(nullptr),
      m_grid(nullptr)
{}


GameController::~GameController()
{
    if (m_queue)
    {
        delete m_queue;
    }
    if (m_grid)
    {
        delete m_grid;
    }
}


void GameController::setGrid(Grid* g)
{
    m_grid = g;
}


void GameController::addUnit(Unit u)
{
    m_queue->push_back(u);
    //TODO: set position on grid...
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
    m_active_unit = m_queue->next();
}
