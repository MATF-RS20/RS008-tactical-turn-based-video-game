#ifndef UNIT_H
#define UNIT_H

#include "Actions/action.h"
#include "player.h"
//#include "Controller/gamecontroller.h"

#include <QGraphicsItem>
#include <iostream>
#include <vector>

class GameController;

class Unit : public QGraphicsItem
{
public:

    //virtual ~Unit() = default;

    //virtual Unit * Copy() const = 0;

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    std::pair<int,int> position() const;
    std::pair<int, int> health() const;
    void updateHealth(int change);
    unsigned getId() const;
    virtual std::string info() const;
    std::vector<Action>* getActions();
    static void setActions(std::vector<Action>* newActions);
    //void setController(GameController* gc);
    //bool move(std::pair<int,int>);
    //void setPos(std::pair<qreal,qreal> position);

protected:
    Unit(int HP, int AP, int initiative, int row, int col, QGraphicsItem* parent = nullptr);
    void setId();

    //HealthPoints, ActionPoints
    int m_max_HP,
        m_remaining_HP,
        m_max_AP,
        m_remaining_AP,
        m_initiative,
        m_row,
        m_col;
    unsigned m_id;
    static unsigned next_id;
    static std::vector<Action>* m_actions;
    //GameController* m_gController;
    Player* m_player;
};

std::ostream& operator<<(std::ostream& out, const Unit& value);









class Warrior: public Unit
{
public:
    Warrior(int HP, int AP, int initiative, int row, int col, QGraphicsItem* parent = nullptr);
    ~Warrior();

    std::string info() const;
private:
    static std::vector<Action>* m_actions;

};






class Healer: public Unit
{
public:
    Healer(int HP, int AP, int initiative, int row, int col, QGraphicsItem* parent = nullptr);
    ~Healer();

    std::string info() const;
private:
    static std::vector<Action>* m_actions;

};



#endif // UNIT_H
