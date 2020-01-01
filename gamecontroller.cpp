#include "gamecontroller.h"

GameController::GameController()
{
    m_queue = new UnitQueue();
}

GameController::~GameController()
{
    if(m_queue)
    {
        delete m_queue;
    }
}
