#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget* parent = nullptr);
    ~GameWindow();
public slots:

    

private:
    Ui::GameWindowClass ui;
};
