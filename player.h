#ifndef PLAYER_H
#define PLAYER_H

#include <QColor>

class Player
{
public:
    Player(std::string name, QColor color);

    QColor color() const;
    std::string name() const;

private:
    QColor m_color;
    std::string m_name;
};

#endif // PLAYER_H
