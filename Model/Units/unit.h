#ifndef UNIT_H
#define UNIT_H

#include "Model/type_definitions.h"
#include "Actions/action.h"
#include "Model/player.h"

#include <QGraphicsItem>

#include <iostream>
#include <vector>


class Unit : public QGraphicsItem
{
public:

    virtual ~Unit() override = default;

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    position_t position() const;
    std::pair<int, int> health() const;
    AP_cost_t AP_left() const; //TODO: think about types to use?
    void updateHealth(int change);
    void updateAP(int change);
    unsigned getId() const;
    std::vector<Action*>* getActions();

    void setPosition(position_t);
    void setActions(std::vector<Action*>* newActions);
    void changeColor(QColor);
    void changeColor();
    Player* player();

    virtual std::string info() const;
    virtual std::string unitClass() const;

protected:
    Unit(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent = nullptr);
    void setId();

    int
        m_remaining_HP, //Health points
        m_max_HP,

        m_remaining_AP, //Action points
        m_max_AP,

        m_initiative;
    unsigned
        m_row,
        m_col;
    unsigned m_id;
    static unsigned next_id;
    std::vector<Action*>* m_actions;
    QColor m_color;
    Player* m_player;
};

std::ostream& operator<<(std::ostream& out, const Unit& value);




class Warrior: public Unit
{
public:
    Warrior(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent = nullptr);
    //Warrior(Unit u); //?
    ~Warrior() override;

    virtual std::string unitClass() const override;
};




class Healer: public Unit
{
public:
    Healer(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent = nullptr);
    ~Healer() override;

    virtual std::string unitClass() const override;
};



#endif // UNIT_H
