#pragma once
#include <iostream>


#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "Plateau.hpp"

namespace front_end {
    class GameWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        GameWindow(QWidget *parent = nullptr);
        ~GameWindow();
        back_end::Plateau* plateau;
    signals:

    public slots:
        void commencerButton();
        void quitterButton();
        //void testBouton();
        void partieNormaleInit();
        //void jouer(int x, int y);
        void syncPlateau();
        static string posToObjName(int x, int y);
        void buttonPressed();
        void bougerPiece(int x1, int y1, int x2, int y2);
        void jouerTour(string pos1, string pos2);
    private:
        //void assignerPos();
        string case1= "";
        string case2 = "";
        bool turn = false; // blanc
        Ui::GameWindowClass ui;
    
    };
}
