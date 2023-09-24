#include <QApplication>

#include "Bank.h"
#include "GuiManager.h"
#include "Database.h"
#include "Account.h"

Bank::Bank()
{
}

Bank::~Bank()
{
}

int Bank::run(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    GuiManager guiManager;
    // Account acc(4, "phoenics", 101, 10000, "phoenics@333");
    // Database::insertIntoAccount(acc);
    Database::retrieve();

    return app.exec();
}
