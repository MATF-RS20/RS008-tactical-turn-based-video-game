#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Units/unit.h"
#include "View/grid.h"
#include "View/actionbutton.h"
#include "View/ui.h"
#include "unitqueue.h"
#include "controller_actions.h"
#include "currentaction.h"

enum ControllerState {init, action_waiting_input, action_ready};


class GameController : public QObject
{
    Q_OBJECT

private:
    UnitQueue* m_queue;
    Unit* m_active_unit;
    Grid* m_grid;
    unsigned m_turn,
        m_field_width,
        m_field_height; //TODO: Make uniform with grid!
    ControllerState m_state = init;
    CurrentAction* m_currentAction = nullptr;
    std::vector<Player*>* m_players;
    // UI:
    QLabel* m_infoLabel;
    QGraphicsScene* m_scene;

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
    std::pair<qreal, qreal> calculatePos(unsigned row, unsigned col) const;
    std::pair<qreal, qreal> calculatePos(std::pair<unsigned, unsigned> position) const;
    //void setState(ControllerState state);
    std::vector<Action*>* getCurrentActions();
    std::string defaultInfo() const;
    void addPlayer(Player*);

private:
    void resetActions();
    void updatePlayer();

private:
    void noActiveUnitError();


public slots:
    void ok();
    void cancel();
    void endTurn();
    //void actionButtonPressed(int button_number);
    void actionButtonPressed(Action* action);
    void actionStarted(Action* action);
    void actionEnded();
    void fieldLeftClicked(std::pair<unsigned, unsigned>);

signals:
    void changeInfo(const QString&);
    void changeInfoPlayer(const QString&);
    void resetActionsOnButtons(std::vector<Action*>* Actions);

};







#endif // GAMECONTROLLER_H
