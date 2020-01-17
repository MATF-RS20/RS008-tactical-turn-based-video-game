#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Units/unit.h"
#include "View/grid.h"
#include "View/actionbutton.h"

#include <vector>
//#include <optional>
#include <QPushButton>

class UnitQueue;

class GameController : public QObject
{
    Q_OBJECT

public:
    GameController(QObject* parent, QPushButton* pb_endTurn, QLabel* showInfo);
    //TODO: singleton maybe?

    ~GameController();

    void setGrid(Grid* g);
    bool addUnit(Unit* u);
    Unit* activeUnit();
    void startGame();

    void add_pb_EndTurn(); //TODO: in constructor. Is this neccesary?
    void add_pb_Action(ActionButton* pb_action);

    void setInfo(std::string msg);
    QString getInfo();

    bool moveUnit (Unit* unit, std::pair<int, int> position);
    //This is for drawing units, setPos()!
    std::pair<qreal, qreal> calculatePos(unsigned row, unsigned col);
    std::pair<qreal, qreal> calculatePos(std::pair<int, int> position);


public slots:
    void endTurn();
    void actionButtonPressed(int button_number);
    //void actionButtonPressed(Action*); //TODO

signals:
    //TODO: Research signals.
    void changeInfo(const QString&);

private:
    UnitQueue* m_queue;
    Unit* m_active_unit;
    Grid* m_grid;
    QLabel* m_infoLabel;
    unsigned m_turn;
    int m_field_width = 40,
        m_field_height = 40;
};
// GameController




class UnitQueue
{
public:
    UnitQueue()
    {
        m_index = 0;
    }

    ~UnitQueue()
    {
        //TODO: smart pointers?
        for (Unit* u : m_vector) {
            delete u;
        }
        m_vector.clear();
    }

    void push_back(Unit* u)
    {
        m_vector.push_back(u); //TODO: see emplace?
    }

    void pop_at(int i)
    {
        if (m_vector.size() > i || i < 0) {
            std::cerr << "UnitQueue pop_at() bad index" << std::endl;
            return;
        }

        m_vector.erase(std::begin(m_vector) + i);

        if (m_index >= i) {
            m_index--;
        }
    }

    //TODO pop_Unit, get_Unit
    /*void pop_Unit(Unit u)
    {
        auto it = std::find(std::begin(m_vector), std::end(m_vector), u);
        //TODO: Redefine Unit == operator?
        //TODO: add m_id to Units for comparison?
    }*/

    //TODO: referance return?
    Unit* current()
    {
        if (m_vector.empty())
        {
            return nullptr;
        }
        return m_vector[m_index];
    }
    //TODO
    Unit* next()
    {
        if (m_vector.empty())
        {
            return nullptr;
        }
        if (m_index >= m_vector.size()-1)
        {
            m_index = 0;
        }
        else {
            m_index++;
        }
        return m_vector[m_index];
    }

private:
    //TODO: different implementation maybe?
    std::vector<Unit*> m_vector;
    int m_index;
};


#endif // GAMECONTROLLER_H
