#pragma once
#include <iostream>


#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "Plateau.hpp"

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    Plateau plateau;
signals:

public slots:
    void commencerButton();
    void quitterButton();
    void testBouton();
private:
    Ui::GameWindowClass ui;
    
};
