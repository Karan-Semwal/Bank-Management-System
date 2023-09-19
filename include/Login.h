#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <memory>

#include "UserType.h"

class Login : public QWidget
{
    Q_OBJECT

public:

    Login(int sizeX, int sizeY);
    ~Login();

    void init();
    UserType processLogin();

private:
    int m_width, m_height;
    std::unique_ptr<QPushButton> m_loginButton;
    std::unique_ptr<QPushButton> m_cancelButton;
    std::unique_ptr<QLabel>      m_loginLabel;
    std::unique_ptr<QLineEdit>   m_username;
    std::unique_ptr<QLineEdit>   m_password;
    std::unique_ptr<QLabel>      m_usernameLabel;
    std::unique_ptr<QLabel>      m_passwordLabel;

public:
    QPushButton* getLoginButton();
    QPushButton* getCancelButton();

};