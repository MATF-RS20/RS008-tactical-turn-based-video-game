#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H

#include <QPushButton>
#include "Model/Actions/action.h"

class ActionButton : public QPushButton
{

    Q_OBJECT

public:
    ActionButton(unsigned button, QWidget* parent);
    //void setText(std::string text);
    //void setAction(Action* action);

private:
    void disable();

public slots:
    void forwardAction(); //wrapper for clicked() signal.
    void setActionsOnButtons(std::vector<Action*>* Actions);

signals:
    void actionUsed(Action* action);
    //void actionUsed(int button);

private:
    Action* m_action;
    unsigned m_button;
};

#endif // ACTIONBUTTON_H
