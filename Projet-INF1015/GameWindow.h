#pragma once
#include <iostream>


#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "Plateau.hpp"

namespace echecs{
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
        //void testBouton();
        void partieNormaleInit();
        void jouer(int x, int y);
        void syncPlateau(shared_ptr<Piece> plateau[8][8]);
    private:
        void assignerPos();
        
        Ui::GameWindowClass ui;
    
};
}
