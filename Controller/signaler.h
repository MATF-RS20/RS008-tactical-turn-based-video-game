#ifndef SIGNALER_H
#define SIGNALER_H

#include "Model/type_definitions.h"

#include <QObject>

// Is this publisher-subscriber?
// TODO: Find design pattern.


class Signaler : public QObject
{
    Q_OBJECT
public:
    explicit Signaler(QObject *parent = nullptr);
    void fieldLeftClick(position_t position);

signals:
    void fieldLeftClickSignal(position_t);

};

#endif // SIGNALER_H
