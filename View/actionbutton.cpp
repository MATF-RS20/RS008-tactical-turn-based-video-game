#include "actionbutton.h"

ActionButton::ActionButton(int button, QWidget* parent)
    : QPushButton("", parent)
    , m_action(nullptr)
    , m_button(button)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(forwardAction()));
}


void ActionButton::forwardAction()
{
    //emit actionUsed(this->m_action);
    std::cerr << "Action button " << m_button << " clicked!" << std::endl;
    emit actionUsed(m_button);
}
