#include "player.h"

Player::Player(QColor color)
    : m_color(color)
{}

QColor Player::color() const
{
    return m_color;
}
