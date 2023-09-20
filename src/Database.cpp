#include "Database.h"
#include <stdio.h>

sqlite3* Database::m_conn;

void Database::connect()
{
    int returnCode{};
    returnCode = sqlite3_open("../xyzbank.db", &m_conn);

    if( returnCode ) {
        fprintf(stderr, "Can't connect to the database: %s\n", sqlite3_errmsg(m_conn));
        return;
    } else {
        fprintf(stderr, "Connected to database successfully\n");
    }
}

void Database::close()
{
    sqlite3_close(m_conn);
}

void Database::insertIntoAccount(Account& account)
{
    connect();

    std::string id      = std::to_string(account.getId());
    std::string name    = account.getName();
    std::string phone   = std::to_string(account.getPhone());
    std::string balance = std::to_string(account.getBalance());
    std::string email   = account.getEmail();

    int retCode{};
    char* errormsg = "Failed to insert into table\n";
    
    // Construct the query using C++ strings
    std::string query = "INSERT INTO Account (Id, Name, Phone, Balance, Email) VALUES ("
                        + id + ", '"
                        + name + "', '"
                        + phone + "', "
                        + balance + ", '"
                        + email + "');";
    
    const char* sql = query.c_str();

    retCode = sqlite3_exec(m_conn, sql, NULL, NULL, &errormsg);
    
    if (retCode != SQLITE_OK) {
        std::cout << "Insertion successful!\n";
        sqlite3_free(errormsg);
    } else {
        std::cout << errormsg;
    }

    close();
}

void Database::retrieve()
{
    Account account;
    connect();

    sqlite3_stmt* stmt;
    const char* query = "SELECT * FROM Account";
    int rc = sqlite3_prepare_v2(m_conn, query, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        std::cout << "Error: " << sqlite3_errmsg(m_conn) << "\n";
    }

    while ((rc = sqlite3_step(stmt) == SQLITE_ROW)) {
        double id                  = sqlite3_column_int(stmt, 0);
        const unsigned char* name  = sqlite3_column_text(stmt, 1);
        double phone               = sqlite3_column_int(stmt, 2);
        double balance             = sqlite3_column_int(stmt, 3);
        const unsigned char* email = sqlite3_column_text(stmt, 4);

        std::cout << id << ", " << name << ", " << phone << ", " << balance << ", " << email << "\n";
    }

    if (rc != SQLITE_DONE) {
        std::cout << "Message: " << sqlite3_errmsg(m_conn) << "\n";
    }
    sqlite3_finalize(stmt);
    close();
}

bool Database::executeQuery(std::string& query)
{
    connect();

    const char* sql = query.c_str();
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(m_conn, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cout << "Query Execution: " << sqlite3_errcode(m_conn) << "\n";
        sqlite3_finalize(stmt);
        close();
        return false;
    }
    sqlite3_finalize(stmt);
    close();
    return true;
}