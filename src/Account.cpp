#include "Account.h"

Account::Account(double id, const std::string& name, double phone, double balance, const std::string& email)
    : m_id(id), m_name(name), m_phone(phone), m_balance(balance), m_email(email)
{
}

void Account::withdraw(double amount)
{
    m_balance += amount;
}

void Account::deposit(double amount)
{
    if (m_balance >= amount) {
        m_balance -= amount;
    }
    std::cout << "Not enough balance!" << std::endl;
}
