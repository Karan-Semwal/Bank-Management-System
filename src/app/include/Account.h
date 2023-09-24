#pragma once
#include <string>
#include <iostream>

class Account
{
public:
    Account() {}
    Account(double id, const std::string& m_name, double phone, double balance, const std::string& email);
    ~Account() {}

    void withdraw(double amount);
    void deposit(double amount);

    void setPhone(double phone)             { m_phone   = phone;   }
    void setId(double id)                   { m_id      = id;      }
    void setBalance(double balance)         { m_balance = balance; }
    void setName(const std::string& name)   { m_name    = name;    }
    void setEmail(const std::string& email) { m_email   = email;   }

    double getPhone()      const { return m_phone;   }
    double getId()         const { return m_id;      }
    double getBalance()    const { return m_balance; }
    std::string getName()  const { return m_name;    }
    std::string getEmail() const { return m_email;   }

private:
    double      m_id;
    std::string m_name;
    double      m_phone;
    double      m_balance;
    std::string m_email;
};