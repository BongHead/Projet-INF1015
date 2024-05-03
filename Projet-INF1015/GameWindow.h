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
        static void nomObjAPos(const string& pos, int& x, int& y);
        static string posANomObj(int x, int y);
        vector<pair<int, int>> getMouvementsValides(shared_ptr<Piece> piece, int x, int y);
        bool dansListe(pair<int, int> move,const vector<pair<int, int>>& validMoves);
        vector<pair<int, int>> valideAdverse(Piece::Couleur);
        vector<pair<int, int>> valideSoi(Piece::Couleur);
        pair<int, int> trouverRoi(Piece::Couleur couleur);
    signals:

    public slots:
        void commencerButton();
        void quitterButton();
        //void testBouton();
        void partieNormaleInit();
        //void jouer(int x, int y);
        void syncPlateau();
        void buttonPressed();
        void bougerPiece(int x1, int y1, int x2, int y2);
        void jouerTour(string pos1, string pos2);
    private:
        //void assignerPos();
        string case1= "";
        string case2 = "";
        bool turn = false; // blanc
        vector<pair<int, int>> mouvementsValides;
        Ui::GameWindowClass ui;
        bool check = false;
        pair<int, int> game_over = { 69, 69 };
    };
}
