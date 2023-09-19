#include "GuiManager.h"

GuiManager::GuiManager()
    : m_loginSize(600, 700),
      m_dashboardSize(800, 800),
      m_login(std::make_unique<Login>(m_loginSize.width(), m_loginSize.height())),
      m_dashboard(std::make_unique<Dashboard>(m_dashboardSize.width(), m_dashboardSize.height()))
{
    m_login->show();
    QObject::connect(m_login->getLoginButton(), &QPushButton::clicked, this, &GuiManager::onLoginClicked);

}

GuiManager::~GuiManager()
{
}

void GuiManager::init()
{

}

void GuiManager::onLoginClicked()
{
    this->m_dashboard->show();
}