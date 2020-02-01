#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Model/type_definitions.h"
#include "Model/Units/unit.h"
#include "View/grid.h"
#include "View/actionbutton.h"
#include "View/ui.h"
#include "unitqueue.h"
#include "action_closure.h"


class GameController : public QObject
{
    Q_OBJECT

public:
    GameController(ui ui);

    ~GameController();
    GameController(const GameController & other) = delete;
    const GameController& operator= (const GameController & other) = delete;


public:
    void setGrid(Grid* g);
    bool addUnit(Unit* u);
    Unit* activeUnit() const;
    void startGame();

    void add_pb_Action(ActionButton* pb_action);

    void setInfo(std::string msg);
    QString getInfo();

    std::string defaultInfo() const;
    std::string fieldInfo(Field* field) const;
    void addPlayer(Player*);

private:
    Field* at(position_t position) const;
    void resetActions();
    void updatePlayer();
    void changeState(ControllerState state);
    void addFieldToClosure(Field* field);

    //Errors:
    [[ noreturn ]] void noActiveUnitError();


public slots:
    void ok();
    void cancel();
    void endTurn();
    //void actionButtonPressed(int button_number);
    void actionButtonPressed(Action* action);
    void actionStart(Action* action);
    void actionEnd();
    void fieldLeftClicked(position_t);

signals:
    void changeInfo(const QString&);
    void changeInfoPlayer(const QString&);
    void resetActionsOnButtons(std::vector<Action*>* Actions);

private:
    UnitQueue* m_queue;
    Unit* m_active_unit;
    Grid* m_grid;
    unsigned m_turn;
    ControllerState m_state = init;
    ActionClosure* m_ActionClosure = nullptr;
    std::vector<Player*>* m_players;
    // UI:
    QPushButton* m_pb_ok;
    QPushButton* m_pb_cancel;
    QLabel* m_infoLabel;
    QGraphicsScene* m_scene;
};







#endif // GAMECONTROLLER_H
