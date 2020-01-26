#ifndef SIGNALER_H
#define SIGNALER_H


#include <QObject>

// Is this publisher-subscriber?
// TODO: Find design pattern.


class Signaler : public QObject
{
    Q_OBJECT
public:
    explicit Signaler(QObject *parent = nullptr);
    void fieldLeftClick(std::pair<unsigned, unsigned> position);

signals:
    void fieldLeftClickSignal(std::pair<unsigned, unsigned>);

};

#endif // SIGNALER_H
