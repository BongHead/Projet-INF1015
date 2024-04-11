#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "Plateau.hpp"
<<<<<<< HEAD

=======
>>>>>>> cd346a258e289fe3510b212ea271cf0dae5d96c7
class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    Plateau plateau;
<<<<<<< HEAD

=======
>>>>>>> cd346a258e289fe3510b212ea271cf0dae5d96c7
signals:

public slots:
    void commencerButton();
    void quitterButton();
private:
    Ui::GameWindowClass ui;
    
};
