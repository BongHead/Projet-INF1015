#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

signals:

public slots:

private:
    Ui::GameWindowClass ui;
};
