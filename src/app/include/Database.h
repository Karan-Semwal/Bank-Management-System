#pragma once
#include <sqlite3.h>
#include <memory>
#include <string>

#include <iostream>
#include "Account.h"

class Database
{
public:
    static void connect();
    static void insertIntoAccount(Account& account);
    static void close();
    static void retrieve();
    static bool executeQuery(const std::string& query);

private:
    static sqlite3 *m_conn;
};