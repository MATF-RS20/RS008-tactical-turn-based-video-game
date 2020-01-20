#ifndef PLAYER_H
#define PLAYER_H

#include <QColor>

class Player
{
public:
    Player(QColor color);

    QColor color() const;

private:
    QColor m_color;
};

#endif // PLAYER_H
