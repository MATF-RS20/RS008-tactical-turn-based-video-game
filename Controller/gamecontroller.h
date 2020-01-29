#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "type_definitions.h"
#include "Units/unit.h"
#include "View/grid.h"
#include "View/actionbutton.h"
#include "View/ui.h"
#include "unitqueue.h"
#include "currentaction.h"


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

    bool moveUnit (Unit* unit, std::pair<unsigned, unsigned> position);
    //This is for drawing units, setPos()!
    std::pair<qreal, qreal> calculatePos(position_t position) const;
    std::string defaultInfo() const;
    void addPlayer(Player*);

private:
    void resetActions();
    void updatePlayer();
    void changeState(ControllerState state);
    //Errors:
    void noActiveUnitError();


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
    paintSize_t
        m_field_width,
        m_field_height; //TODO: Make uniform with grid!
    ControllerState m_state = init;
    CurrentAction* m_currentAction = nullptr;
    std::vector<Player*>* m_players;
    // UI:
    QPushButton* m_pb_ok;
    QPushButton* m_pb_cancel;
    QLabel* m_infoLabel;
    QGraphicsScene* m_scene;
};







#endif // GAMECONTROLLER_H
