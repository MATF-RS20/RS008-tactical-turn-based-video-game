#include "signaler.h"

Signaler::Signaler(QObject *parent)
    : QObject(parent)
{

}

void Signaler::fieldLeftClick(std::pair<unsigned int, unsigned int> position)
{
    emit fieldLeftClickSignal(position);
}
