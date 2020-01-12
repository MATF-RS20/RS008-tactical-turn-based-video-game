#include "Controller/gamecontroller.h"
#include "Units/unit.h"
#include "Levels/levels.h"
#include "View/ui.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    makeUI();

    //TODO: Timer.

    return app.exec();
}
