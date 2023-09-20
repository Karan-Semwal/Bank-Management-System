#include "GuiManager.h"

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
    m_login->processLogin();
    // open dashboard window
    m_dashboard->show();
    m_login->close();
}
