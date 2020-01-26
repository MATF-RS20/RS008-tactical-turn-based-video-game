#include "actionbutton.h"

ActionButton::ActionButton(unsigned button, QWidget* parent)
    : QPushButton("", parent)
    , m_action(nullptr)
    , m_button(button)
{
    // TODO: make uiButton and set minimum width there!
    setMinimumWidth(100);
    setEnabled(false);
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(forwardAction()));
}


void ActionButton::forwardAction()
{
    //std::cerr << "Action button " << m_button << " clicked!" << std::endl;
    emit actionUsed(m_action);
    //emit actionUsed(m_button);
}


void ActionButton::disable()
{
    setEnabled(false);
    m_action = nullptr;
    setText("");
}


void ActionButton::setActionsOnButtons(std::vector<Action*>* Actions)
{
    if (!Actions) {
        disable();
    }

    if (m_button >= Actions->size()) {
        disable();
    }
    else {
        m_action = (*Actions)[m_button];
        if (m_action == nullptr)
        {
            disable();
        }
        else {
            setEnabled(true);
            QString name = (m_action->name()).c_str();
            setText(name);
        }

    }
}
