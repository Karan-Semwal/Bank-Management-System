#include "Dashboard.h"

Dashboard::Dashboard(int sizeX, int sizeY)
    : m_width(sizeX), m_height(sizeY)
{
    this->setMinimumSize(m_width, m_height);
    this->setWindowTitle("XYZ Bank");
    init();
}

Dashboard::~Dashboard()
{
}

void Dashboard::init()
{
    this->setWindowState(Qt::WindowMaximized);
    this->setStyleSheet("background-color: #b9b4c7");

}
