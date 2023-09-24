#include "GuiManager.h"
#include <iostream>
#include "Database.h"

GuiManager::GuiManager()
    : userType(UserType::NONE),
      m_loginSize(600, 700),
      m_dashboardSize(1000, 800),
      m_login(std::make_unique<Login>(m_loginSize.width(), m_loginSize.height())),
      m_dashboard(std::make_unique<Dashboard>(m_dashboardSize.width(), m_dashboardSize.height()))
{
    m_login->show();
    
    QObject::connect(m_login->getLoginButton(),  &QPushButton::clicked, this, &GuiManager::onLoginClicked);
    QObject::connect(m_login->getCancelButton(), &QPushButton::clicked, this, [&]() {
        this->m_login->close();
    });
}

GuiManager::~GuiManager()
{
}

void GuiManager::init()
{
}

void GuiManager::onLoginClicked()
{
    // validate the login details
    UserType usertype = m_login->processLogin();

    if (!Database::executeQuery("SELECT * FROM CustomerCredentials;")) {
        std::cerr << "Failed to exectute\n";
    }

    switch (usertype)
    {
    case UserType::NONE:
        std::cout << "None" << std::endl;
        break;
    case UserType::CUSTOMER:
        // use customer dashboard
        break;
    case UserType::TELLER:
        // use teller dashboard
    break;
    case UserType::ADMIN:
        // use admin dashboard
        break;
    default:
        break;
    }
    // open dashboard window
    m_dashboard->show();
    m_login->close();
}
