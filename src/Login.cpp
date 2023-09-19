#include "Login.h"

Login::Login(int sizeX, int sizeY)
    : m_loginButton(std::make_unique<QPushButton>("Login", this)),
      m_cancelButton(std::make_unique<QPushButton>("Cancel", this)),
      m_loginLabel(std::make_unique<QLabel>("Login", this)),
      m_username(std::make_unique<QLineEdit>(this)),
      m_password(std::make_unique<QLineEdit>(this)),
      m_usernameLabel(std::make_unique<QLabel>("Username", this)),
      m_passwordLabel(std::make_unique<QLabel>("Password", this)),
      m_width(sizeX), m_height(sizeY)
{
    this->setFixedSize(m_width, m_height);
    this->setWindowTitle("Login");
    init();
}

void Login::events()
{

}

Login::~Login()
{
}

UserType Login::processLogin()
{
    return UserType::CUSTOMER;
}

QPushButton* Login::getLoginButton() {
    return m_loginButton.get(); 
}

QPushButton* Login::getCancelButton() {
    return m_cancelButton.get();
}

void Login::init()
{
    int x = m_width / 2  - (100 / 2);
    int y = m_height - (200 / 2);
    m_loginButton->setGeometry(x - 60, y - 50, 100, 40); // x, y, w, h
    m_loginButton->show();

    m_cancelButton->setGeometry(x + 60, y - 50, 100, 40); // x, y, w, h
    m_cancelButton->show();

    QFont font;
    font.setPointSize(35);
    font.setBold(true);

    x = m_width / 2  - (200 / 2);
    y = 0 + (m_height / 9);
    m_loginLabel->setGeometry(x, y, 200 - 20, 100);
    m_loginLabel->setAlignment(Qt::AlignCenter);
    m_loginLabel->setFont(font);
    m_loginLabel->show();

    font.setPointSize(12);
    font.setBold(false);

    m_usernameLabel->setGeometry(x, y + 150, 200, 50);
    m_usernameLabel->setAlignment(Qt::AlignCenter);
    m_usernameLabel->setFont(font);

    m_passwordLabel->setGeometry(x, y + 350 - 50, 200, 50);
    m_passwordLabel->setAlignment(Qt::AlignCenter);
    m_passwordLabel->setFont(font);

    m_username->setGeometry(x - 100, y + 200, 400, 40);
    m_username->setCursorPosition(100);
    m_username->setPlaceholderText("username");
    m_username->setAlignment(Qt::AlignCenter);

    m_password->setGeometry(x - 100, y + 400 - 50, 400, 40);
    m_password->setPlaceholderText("password");
    m_password->setCursorPosition(100);
    m_password->setAlignment(Qt::AlignCenter);
}
