/**
* Implémentation de la classe GameWindow.
* \file   GameWindow.cpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/

#include "GameWindow.h"


front_end::GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent), plateau(new back_end::Plateau)
{
    ui.setupUi(this);
    QPixmap pix(":/GameWindow/images/Board.png");
    int x = ui.BoardImg->width();
    int y = ui.BoardImg->height();
    ui.BoardImg->setPixmap(pix.scaled(x,y,Qt::KeepAspectRatio));
}

front_end::GameWindow::~GameWindow()
{
    delete plateau;
}

void front_end::GameWindow::commencerButton() {
    ui.GameTitle->setVisible(false);
    ui.gameHider->setVisible(false);
    ui.CommencerButton->setVisible(false);
    ui.QuitterButton->setVisible(false);
}

void front_end::GameWindow::quitterButton() {
    auto reply = QMessageBox::question(this, "Quitter?", "\"Chess is... no different from Tic-Tac-Toe.\" - 1/2 Kohaku", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
        close();
}

void front_end::GameWindow::partieNormaleInit() {
    delete plateau;
    plateau = new back_end::Plateau(back_end::Plateau::normal);
    syncPlateau();
    ui.PartieNormaleButton->setVisible(false);
    ui.posRandomButton->setVisible(false);
    ui.posRandomButton2->setVisible(false);
    turn_ = false;
}

void front_end::GameWindow::partieRandom1Init() {
    delete plateau;
    plateau = new back_end::Plateau(back_end::Plateau::random1);
    syncPlateau();
    ui.PartieNormaleButton->setVisible(false);
    ui.posRandomButton->setVisible(false);
    ui.posRandomButton2->setVisible(false);
    turn_ = false;
}

void front_end::GameWindow::partieRandom2Init() {
    delete plateau;
    plateau = new back_end::Plateau(back_end::Plateau::random2);
    syncPlateau();
    ui.PartieNormaleButton->setVisible(false);
    ui.posRandomButton->setVisible(false);
    ui.posRandomButton2->setVisible(false);
    turn_ = false;
}

bool front_end::GameWindow::estDansListe(pair<int, int> move,const vector<pair<int, int>>& mouvementsValides) {
    size_t size = mouvementsValides.size();
    for (int i = 0; i < size; i++) {
        //cout << "compare " << move.first << ',' << move.second << " " << mouvementsValides[i].first << ',' << mouvementsValides[i].second << endl;
        if (move == mouvementsValides[i]) {
            return true;
        }
    }
    return false;
}

pair<int, int> front_end::GameWindow::trouverRoi(Piece::Couleur couleur) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            shared_ptr<Piece> autrePiece = plateau->casePiece[i][j];
            if ((autrePiece != nullptr) && (autrePiece->getCouleur() != couleur) && (autrePiece->getType() == Piece::Roi)) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(69, 69);
}

vector<pair<int, int>> front_end::GameWindow::validerSoi(Piece::Couleur couleur) {
    vector<pair<int, int>> soi;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            shared_ptr<Piece> autrePiece = plateau->casePiece[i][j];
            if ((autrePiece != nullptr) && (autrePiece->getCouleur() == couleur) && (autrePiece->getType() != Piece::Roi)) {
                vector<pair<int, int>> otherMoves = getMouvementsValides(autrePiece, i, j);
                soi.insert(soi.end(), otherMoves.begin(), otherMoves.end());
            }
            else if ((autrePiece != nullptr) && (autrePiece->getCouleur() == couleur) && (autrePiece->getType() == Piece::Roi)) {
                soi.push_back(make_pair(i + 1, j + 1));
                soi.push_back(make_pair(i + 1, j - 1));
                soi.push_back(make_pair(i - 1, j + 1));
                soi.push_back(make_pair(i - 1, j - 1));
                soi.push_back(make_pair(i + 1, j));
                soi.push_back(make_pair(i - 1, j));
                soi.push_back(make_pair(i, j + 1));
                soi.push_back(make_pair(i, j - 1));
            }
        }
    }
    return soi;
}

vector<pair<int, int>> front_end::GameWindow::validerAdverse(Piece::Couleur couleur) {
    vector<pair<int, int>> adversaire;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            shared_ptr<Piece> autrePiece = plateau->casePiece[i][j];
            if ((autrePiece != nullptr) && (autrePiece->getCouleur() != couleur) && (autrePiece->getType() != Piece::Roi)) {
                vector<pair<int, int>> otherMoves = getMouvementsValides(autrePiece, i, j);
                adversaire.insert(adversaire.end(), otherMoves.begin(), otherMoves.end());
            }
            else if ((autrePiece != nullptr) && (autrePiece->getCouleur() != couleur) && (autrePiece->getType() == Piece::Roi)) {
                adversaire.push_back(make_pair(i + 1, j + 1));
                adversaire.push_back(make_pair(i + 1, j - 1));
                adversaire.push_back(make_pair(i - 1, j + 1));
                adversaire.push_back(make_pair(i - 1, j - 1));
                adversaire.push_back(make_pair(i + 1, j));
                adversaire.push_back(make_pair(i - 1, j));
                adversaire.push_back(make_pair(i, j + 1));
                adversaire.push_back(make_pair(i, j - 1));
            }
        }
    }
    return adversaire;
}

vector<pair<int, int>> front_end::GameWindow::getMouvementsValides(shared_ptr<Piece> piece, int x, int y) {
    vector<pair<int, int>> getMouvements;
    switch (piece->getType()) {
    case Piece::Cavalier:
        if ((x + 2 <= 7 && y + 1 <= 7) && ((plateau->casePiece[x + 2][y + 1] == nullptr) || (plateau->casePiece[x + 2][y + 1]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x + 2, y + 1));
        }
        if ((x + 2 <= 7 && y - 1 >= 0) && ((plateau->casePiece[x + 2][y - 1] == nullptr) || (plateau->casePiece[x + 2][y - 1]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x + 2, y - 1));
        }
        if ((x - 2 >= 0 && y + 1 <= 7) && ((plateau->casePiece[x - 2][y + 1] == nullptr) || (plateau->casePiece[x - 2][y + 1]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x - 2, y + 1));
        }
        if ((x - 2 >= 0 && y - 1 >= 0) && ((plateau->casePiece[x - 2][y - 1] == nullptr) || (plateau->casePiece[x - 2][y - 1]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x - 2, y - 1));
        }
        if ((x + 1 <= 7 && y + 2 <= 7) && ((plateau->casePiece[x + 1][y + 2] == nullptr) || (plateau->casePiece[x + 1][y + 2]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x + 1, y + 2));
        }
        if ((x + 1 <= 7 && y - 2 >= 0) && ((plateau->casePiece[x + 1][y - 2] == nullptr) || (plateau->casePiece[x + 1][y - 2]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x + 1, y - 2));
        }
        if ((x - 1 >= 0 && y + 2 <= 7) && ((plateau->casePiece[x - 1][y + 2] == nullptr) || (plateau->casePiece[x - 1][y + 2]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x - 1, y + 2));
        }
        if ((x - 1 >= 0 && y - 2 >= 0) && ((plateau->casePiece[x - 1][y - 2] == nullptr) || (plateau->casePiece[x - 1][y - 2]->getCouleur() != piece->getCouleur()))) {
            getMouvements.push_back(make_pair(x - 1, y - 2));
        }
        break;
    case Piece::Tour:
        for (int i = x + 1; i <= 7; i++) {
            if (plateau->casePiece[i][y] == nullptr) {
                getMouvements.push_back(make_pair(i, y));
            }
            else if (plateau->casePiece[i][y]->getCouleur() != piece->getCouleur()) {
                getMouvements.push_back(make_pair(i, y));
                break;
            }
            else if (plateau->casePiece[i][y]->getCouleur() == piece->getCouleur())
                break;
        }
        for (int i = x - 1; i >=0 ; i--) {
            if (plateau->casePiece[i][y] == nullptr) {
                getMouvements.push_back(make_pair(i, y));
            }
            else if (plateau->casePiece[i][y]->getCouleur() != piece->getCouleur()) {
                getMouvements.push_back(make_pair(i, y));
                break;
            }
            else if (plateau->casePiece[i][y]->getCouleur() == piece->getCouleur())
                break;
        }
        for (int i = y + 1; i <= 7; i++) {
            if (plateau->casePiece[x][i] == nullptr) {
                getMouvements.push_back(make_pair(x, i));
            }
            else if (plateau->casePiece[x][i]->getCouleur() != piece->getCouleur()) {
                getMouvements.push_back(make_pair(x, i));
                break;
            }
            else if (plateau->casePiece[x][i]->getCouleur() == piece->getCouleur())
                break;
        }
        for (int i = y - 1; i >= 0; i--) {
            if (plateau->casePiece[x][i] == nullptr) {
                getMouvements.push_back(make_pair(x, i));
            }
            else if (plateau->casePiece[x][i]->getCouleur() != piece->getCouleur()) {
                getMouvements.push_back(make_pair(x, i));
                break;
            }
            else if (plateau->casePiece[x][i]->getCouleur() == piece->getCouleur())
                break;
        }
        break;
    case Piece::Roi:
        vector<pair<int, int>> mouvementIllegaux = validerAdverse(piece->getCouleur());
        if ((x + 1 <= 7 && y + 1 <= 7) && ((plateau->casePiece[x + 1][y + 1] == nullptr || plateau->casePiece[x + 1][y + 1]->getCouleur() != piece->getCouleur()) 
            && !estDansListe(make_pair(x + 1, y + 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x + 1, y + 1));
        }
        if ((x + 1 <= 7 && y - 1 >= 0) && ((plateau->casePiece[x + 1][y - 1] == nullptr || plateau->casePiece[x + 1][y - 1]->getCouleur() != piece->getCouleur()) 
            && !estDansListe(make_pair(x + 1, y - 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x + 1, y - 1));
        }
        if ((x - 1 >= 0 && y + 1 <= 7) && ((plateau->casePiece[x - 1][y + 1] == nullptr || plateau->casePiece[x - 1][y + 1]->getCouleur() != piece->getCouleur()) 
            && !estDansListe(make_pair(x - 1, y + 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x - 1, y + 1));
        }
        if ((x - 1 >= 0 && y - 1 >= 0) && ((plateau->casePiece[x - 1][y - 1] == nullptr || plateau->casePiece[x - 1][y - 1]->getCouleur() != piece->getCouleur()) 
            && !estDansListe(make_pair(x - 1, y - 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x - 1, y - 1));
        }
        if ((x + 1 <= 7) && ((plateau->casePiece[x + 1][y] == nullptr || plateau->casePiece[x + 1][y]->getCouleur() != piece->getCouleur())
            && !estDansListe(make_pair(x + 1, y), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x + 1, y));
        }
        if ((x - 1 >= 0) && ((plateau->casePiece[x - 1][y] == nullptr || plateau->casePiece[x - 1][y]->getCouleur() != piece->getCouleur())
            && !estDansListe(make_pair(x - 1, y), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x - 1, y));
        }
        if ((y + 1 <= 7) && ((plateau->casePiece[x][y + 1] == nullptr || plateau->casePiece[x][y + 1]->getCouleur() != piece->getCouleur())
            && !estDansListe(make_pair(x, y + 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x, y + 1));
        }
        if ((y - 1 >= 0) && ((plateau->casePiece[x][y - 1] == nullptr || plateau->casePiece[x][y - 1]->getCouleur() != piece->getCouleur())
            && !estDansListe(make_pair(x, y - 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x, y - 1));
        }
        break;
    }
    return getMouvements;
}

void front_end::GameWindow::buttonPressed() {
    Case* senderButton = qobject_cast<Case*>(sender());
    string objectName = senderButton->objectName().toStdString();
    int x, y, x2, y2;
    nomObjAPos(objectName, x, y);
    if (plateau->casePiece[x][y] == nullptr && case1_ == "") {
        ui.StatusLabel->setText("Case vide");
        //cout << "Case vide" << endl;
        return;
    }
    if (((!turn_) && (case1_ == "") && (plateau->casePiece[x][y]->getCouleur() == Piece::noir)) 
        or ((turn_) && (case1_ == "") && (plateau->casePiece[x][y]->getCouleur() == Piece::blanc))) {
        ui.StatusLabel->setText("Attend ton tour mon enfant.");
        //cout << "Attend ton tour mon enfant" << endl;
        return;
    }

    if (case1_ == "") {
        mouvementsValides_ = getMouvementsValides(plateau->casePiece[x][y], x, y);
        /*for (int i = 0; i < mouvementsValides_.size(); i++) {
            cout << mouvementsValides_[i].first << ',' << mouvementsValides_[i].second << endl;
        }*/
        case1_ = objectName;
    }
    else if (case2_ == "") {
        nomObjAPos(objectName, x2, y2);
        if (!estDansListe(make_pair(x2, y2), mouvementsValides_)) {
            ui.StatusLabel->setText("Invalide.");
            //cout << "Invalide" << endl;
            return;
        }
        case2_ = objectName;
        jouerTour(case1_, case2_);
    }
    ui.posLabel->setText(senderButton->objectName().toStdString().c_str());
    //cout << senderButton->objectName().toStdString() << endl;
}

void front_end::GameWindow::bougerPiece(int x1, int y1, int x2, int y2) {
    plateau->casePiece[x2][y2] = std::move(plateau->casePiece[x1][y1]);
    syncPlateau();
}

void front_end::GameWindow::jouerTour(string pos1, string pos2) {
    //cout << pos1[0];
    int x1 , x2, y1, y2;
    nomObjAPos(pos1, x1, y1);
    nomObjAPos(pos2, x2, y2);
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
    bougerPiece(x1, y1, x2, y2);
    mouvementsValides_.clear();
    Piece::Couleur couleur = plateau->casePiece[x2][y2]->getCouleur();
    vector<pair<int, int>> soi = validerSoi(couleur);
    pair<int, int> roiAdverse = trouverRoi(couleur);
    if (roiAdverse == game_over_) {
        ui.StatusLabel->setText("Game over");
        ui.PartieNormaleButton->setVisible(true);
        ui.posRandomButton->setVisible(true);
        ui.posRandomButton2->setVisible(true);
    }
    if (estDansListe(roiAdverse, soi)) {
        check_ = true;
        ui.StatusLabel->setText(format("{},{} check", roiAdverse.first, roiAdverse.second).c_str());
        //cout << roiAdverse.first << ',' << roiAdverse.second << " check" << endl;
        mouvementsValides_ = getMouvementsValides(plateau->casePiece[roiAdverse.first][roiAdverse.second], roiAdverse.first, roiAdverse.second);
        if (mouvementsValides_.size() == 0) {
            ui.StatusLabel->setText("Stalemate");
            //cout << "Stalemate";
        }
        case1_ = posANomObj(roiAdverse.first, roiAdverse.second);
    }
    else {
        case1_ = "";
    }
    case2_ = "";
    turn_ = !turn_;
    if (!turn_)
        ui.CompteurTour->setText("Blanc à jouer");
    else
        ui.CompteurTour->setText("Noir à jouer");
}



void front_end::GameWindow::syncPlateau() const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto piece = plateau->casePiece[i][j];
            string position = posANomObj(i, j); 
            auto caseButton = findChild<Case*>(position);
            
            if (piece == nullptr) {
                caseButton->changerEtat(Case::vide);
                continue;
            }
            switch (piece->getType()) {
            case Piece::Pion:
                if (piece->getCouleur() == Piece::blanc)
                    caseButton->changerEtat(Case::pionBlanc);   
                else
                    caseButton->changerEtat(Case::pionNoir);
                break;
            case Piece::Tour:
                if (piece->getCouleur() == Piece::blanc)
                    caseButton->changerEtat(Case::tourBlanc);
                else
                    caseButton->changerEtat(Case::tourNoir);
                break;
            case Piece::Cavalier:
                if (piece->getCouleur() == Piece::blanc)
                    caseButton->changerEtat(Case::cavalierBlanc);
                else
                    caseButton->changerEtat(Case::cavalierNoir);
                break;
            case Piece::Roi:
                if (piece->getCouleur() == Piece::blanc)
                    caseButton->changerEtat(Case::roiBlanc);
                else
                    caseButton->changerEtat(Case::roiNoir);
                break;
            default:
                caseButton->changerEtat(Case::vide);
                break;
            }
            
            
        }
    }
}

string front_end::GameWindow::posANomObj(int x, int y) {
    string combine = "";
    char lettre = y + 97;
    combine += lettre;
    combine += '0' + (8-x);
    return combine;
}

void front_end::GameWindow::nomObjAPos(const string& pos, int &x, int &y) {
    y = pos[0] - 97;
    x = 8 - pos[1] + '0';
}