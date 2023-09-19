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

































    // sqlite3* db;
    // char* errMsg = nullptr;
    
    // // Open or create a SQLite database
    // int rc = sqlite3_open("test.db", &db);
    // if (rc != SQLITE_OK) {
    //     std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
    //     sqlite3_close(db);
    //     return rc;
    // }

    // // Create a table
    // const char* createTableSQL = "CREATE TABLE IF NOT EXISTS test_table (id INTEGER PRIMARY KEY, name TEXT);";
    // rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
    // if (rc != SQLITE_OK) {
    //     std::cerr << "SQL error: " << errMsg << std::endl;
    //     sqlite3_free(errMsg);
    //     sqlite3_close(db);
    //     return rc;
    // }

    // // Insert data
    // const char* insertSQL = "INSERT INTO test_table (name) VALUES ('John');";
    // rc = sqlite3_exec(db, insertSQL, nullptr, nullptr, &errMsg);
    // if (rc != SQLITE_OK) {
    //     std::cerr << "SQL error: " << errMsg << std::endl;
    //     sqlite3_free(errMsg);
    //     sqlite3_close(db);
    //     return rc;
    // }

    // // Retrieve data
    // const char* selectSQL = "SELECT * FROM test_table;";
    // sqlite3_stmt* stmt;
    // rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);
    // if (rc != SQLITE_OK) {
    //     std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    //     sqlite3_close(db);
    //     return rc;
    // }

    // while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    //     int id = sqlite3_column_int(stmt, 0);
    //     const unsigned char* name = sqlite3_column_text(stmt, 1);
    //     std::cout << "ID: " << id << ", Name: " << name << std::endl;
    // }

    // sqlite3_finalize(stmt);
    // sqlite3_close(db);
