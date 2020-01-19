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
    std::cerr << "Action button " << m_button << " clicked!" << std::endl;
    emit actionUsed(m_action);
    //emit actionUsed(m_button);
}


void ActionButton::setActions(std::vector<Action>* Actions)
{
    if (m_button > Actions->size())
    {
        m_action = nullptr;
        setText("");
    }
    else {
        m_action = &((*Actions)[m_button]);
        if (m_action == nullptr)
        {
            setText("");
        }
        else {
            QString name = (m_action->name()).c_str();
            setText(name);
        }

    }
}

//void ActionButton::setText(std::string text){}
