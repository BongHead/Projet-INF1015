/**
* Classe gérant l'affichage, les signaux, et les slots. Toute la logique se trouve ici.
* \file   GameWindow.h
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#pragma once
#include <iostream>
#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"
#include <QPixmap>
#include <QMessageBox>
#include<string>
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
        Ui::GameWindowClass ui;
        
    signals:

    public slots:
        void commencerButton();
        void quitterButton();
        
        void partieNormaleInit();
        void partieRandom1Init();
        void partieRandom2Init();
        
        void syncPlateau() const;
        void buttonPressed();
        void bougerPiece(int x1, int y1, int x2, int y2);
        void jouerTour(string pos1, string pos2);
    private:
        vector<pair<int, int>> getMouvementsValides(shared_ptr<Piece> piece, int x, int y);
        bool estDansListe(pair<int, int> move, const vector<pair<int, int>>& validMoves);
        vector<pair<int, int>> validerAdverse(Piece::Couleur);
        vector<pair<int, int>> validerSoi(Piece::Couleur);
        pair<int, int> trouverRoi(Piece::Couleur couleur);



        string case1_ = "";
        string case2_ = "";
        bool turn_ = false; // blanc
        vector<pair<int, int>> mouvementsValides_;
        bool check_ = false;
        pair<int, int> game_over_ = { 69, 69 };
        
    };
}
