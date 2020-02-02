#include "Controller/gamecontroller.h"
#include "Levels/levels.h"
#include "View/ui.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ui ui = makeUI();

    GameController* gc = createLevel1(ui);
    gc->startGame(&app);

    ui.window->show();

    return app.exec();
}
