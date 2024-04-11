#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QMessageBox>

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

signals:

public slots:
    void commencerButton();
    void quitterButton();
private:
    Ui::GameWindowClass ui;
    
};
