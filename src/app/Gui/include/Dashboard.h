#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <memory>

class Dashboard : public QWidget
{
public:

    Dashboard(int sizeX, int sizeY);
    ~Dashboard();

    void init();

private:
    int m_width, m_height;

};