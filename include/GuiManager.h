#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <memory>

#include "Login.h"
#include "Dashboard.h"

class GuiManager : public QWidget
{
public:
    GuiManager();
    ~GuiManager();

    void init();

public:
    UserType userType;
    
private:
    QSize m_loginSize;
    QSize m_dashboardSize;
    std::unique_ptr<Login>     m_login;
    std::unique_ptr<Dashboard> m_dashboard;

private slots:
    void onLoginClicked();

};