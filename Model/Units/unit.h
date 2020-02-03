#ifndef UNIT_H
#define UNIT_H

#include "Model/type_definitions.h"
#include "Model/Actions/action.h"
#include "Model/player.h"

#include <QGraphicsItem>

#include <iostream>
#include <vector>

#define DEFAULT_OUTLINE_COLOR Qt::black
#define DEFAULT_HIGHLIGHT_COLOR Qt::red


class Unit : public QGraphicsItem
{
public:

    virtual ~Unit() override = default;

    QRectF boundingRect() const override;

    virtual void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    void paintWithText(QString text, QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget);

    position_t position() const;

    AP_cost_t AP_left() const; //TODO: think about types to use?
    int HP_left() const;
    void updateHealth(int change);
    void updateHealth(unsigned change);
    void updateAP(int change);

    unsigned getId() const;
    std::vector<Action*>* getActions();

    void setPosition(position_t);
    void setActions(std::vector<Action*>* newActions);
    void changeColor(QColor);
    void changeColor();
    void highlight();
    void unHighlight();
    Player* player();

    unsigned id();
    bool operator==(Unit& other);
    bool operator!=(Unit& other);

    virtual std::string info() const;
    virtual std::string unitClass() const;

protected:
    Unit(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent = nullptr);
    void setId();

    int
        m_remaining_HP, //Health points
        m_max_HP,
        m_HP_regen,

        m_remaining_AP, //Action points
        m_max_AP,
        m_AP_regen,

        m_initiative;
    unsigned
        m_row,
        m_col;
    unsigned m_id;
    static unsigned next_id;
    std::vector<Action*>* m_actions;
    QColor m_color;
    QColor m_outline_color = DEFAULT_OUTLINE_COLOR;
    Player* m_player;
};

std::ostream& operator<<(std::ostream& out, const Unit& value);




class Warrior: public Unit
{
public:
    Warrior(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent = nullptr);
    Warrior(unsigned row, unsigned col, Player* player);

    ~Warrior() override;

    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    virtual std::string unitClass() const override;
};




class Healer: public Unit
{
public:
    Healer(int HP, int AP, int initiative, unsigned row, unsigned col, Player* player, std::vector<Action*>* actions, QGraphicsItem* parent = nullptr);
    Healer(unsigned row, unsigned col, Player* player);

    ~Healer() override;

    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    virtual std::string unitClass() const override;
};



#endif // UNIT_H
