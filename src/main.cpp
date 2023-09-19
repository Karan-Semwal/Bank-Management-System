#include <QApplication>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include <iostream>
#include <sqlite3.h>

#include "GuiManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GuiManager guiManager;

    return app.exec();

}
