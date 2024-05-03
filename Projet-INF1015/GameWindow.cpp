#include "GameWindow.h"
#include<string>

front_end::GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent), plateau(new back_end::Plateau)
{
    ui.setupUi(this);


    //==============================
    ui.CommencerButton->setVisible(false);
    ui.QuitterButton->setVisible(false);
    ui.GameTitle->setVisible(false);
    //==============================
    

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
}

bool front_end::GameWindow::dansListe(pair<int, int> move,const vector<pair<int, int>>& mouvementsValides) {
    int size = mouvementsValides.size();
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

vector<pair<int, int>> front_end::GameWindow::valideSoi(Piece::Couleur couleur) {
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

vector<pair<int, int>> front_end::GameWindow::valideAdverse(Piece::Couleur couleur) {
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
        vector<pair<int, int>> mouvementIllegaux = valideAdverse(piece->getCouleur());
        if ((x + 1 <= 7 && y + 1 <= 7) && ((plateau->casePiece[x + 1][y + 1] == nullptr || plateau->casePiece[x + 1][y + 1]->getCouleur() != piece->getCouleur()) 
            && !dansListe(make_pair(x + 1, y + 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x + 1, y + 1));
        }
        if ((x + 1 <= 7 && y - 1 >= 0) && ((plateau->casePiece[x + 1][y - 1] == nullptr || plateau->casePiece[x + 1][y - 1]->getCouleur() != piece->getCouleur()) 
            && !dansListe(make_pair(x + 1, y - 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x + 1, y - 1));
        }
        if ((x - 1 >= 0 && y + 1 <= 7) && ((plateau->casePiece[x - 1][y + 1] == nullptr || plateau->casePiece[x - 1][y + 1]->getCouleur() != piece->getCouleur()) 
            && !dansListe(make_pair(x - 1, y + 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x - 1, y + 1));
        }
        if ((x - 1 >= 0 && y - 1 >= 0) && ((plateau->casePiece[x - 1][y - 1] == nullptr || plateau->casePiece[x - 1][y - 1]->getCouleur() != piece->getCouleur()) 
            && !dansListe(make_pair(x - 1, y - 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x - 1, y - 1));
        }
        if ((x + 1 <= 7) && ((plateau->casePiece[x + 1][y] == nullptr || plateau->casePiece[x + 1][y]->getCouleur() != piece->getCouleur())
            && !dansListe(make_pair(x + 1, y), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x + 1, y));
        }
        if ((x - 1 >= 0) && ((plateau->casePiece[x - 1][y] == nullptr || plateau->casePiece[x - 1][y]->getCouleur() != piece->getCouleur())
            && !dansListe(make_pair(x - 1, y), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x - 1, y));
        }
        if ((y + 1 <= 7) && ((plateau->casePiece[x][y + 1] == nullptr || plateau->casePiece[x][y + 1]->getCouleur() != piece->getCouleur())
            && !dansListe(make_pair(x, y + 1), mouvementIllegaux))) {
            getMouvements.push_back(make_pair(x, y + 1));
        }
        if ((y - 1 >= 0) && ((plateau->casePiece[x][y - 1] == nullptr || plateau->casePiece[x][y - 1]->getCouleur() != piece->getCouleur())
            && !dansListe(make_pair(x, y - 1), mouvementIllegaux))) {
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
    if (plateau->casePiece[x][y] == nullptr && case1 == "") {
        cout << "Case vide" << endl;
        return;
    }
    if (((!turn) && (case1 == "") && (plateau->casePiece[x][y]->getCouleur() == Piece::noir)) 
        or ((turn) && (case1 == "") && (plateau->casePiece[x][y]->getCouleur() == Piece::blanc))) {
        cout << "Attend ton tour mon enfant" << endl;
        return;
    }

    if (case1 == "") {
        mouvementsValides = getMouvementsValides(plateau->casePiece[x][y], x, y);
        for (int i = 0; i < mouvementsValides.size(); i++) {
            cout << mouvementsValides[i].first << ',' << mouvementsValides[i].second << endl;
        }
        case1 = objectName;
    }
    else if (case2 == "") {
        nomObjAPos(objectName, x2, y2);
        if (!dansListe(make_pair(x2, y2), mouvementsValides)) {
            cout << "Invalide" << endl;
            return;
        }
        case2 = objectName;
        jouerTour(case1, case2);
    }
    cout << senderButton->objectName().toStdString() << endl;
}

void front_end::GameWindow::bougerPiece(int x1, int y1, int x2, int y2) {
    plateau->casePiece[x2][y2] = std::move(plateau->casePiece[x1][y1]);
    //plateau->casePiece[x1][y1] = nullptr;
    syncPlateau();
}
void front_end::GameWindow::jouerTour(string pos1, string pos2) {
    cout << pos1[0];
    int x1 , x2, y1, y2;
    nomObjAPos(pos1, x1, y1);
    nomObjAPos(pos2, x2, y2);
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
    bougerPiece(x1, y1, x2, y2);
    mouvementsValides.clear();
    Piece::Couleur couleur = plateau->casePiece[x2][y2]->getCouleur();
    vector<pair<int, int>> soi = valideSoi(couleur);
    pair<int, int> roiAdverse = trouverRoi(couleur);
    if (roiAdverse == game_over) {
        cout << "Game Over";
    }
    if (dansListe(roiAdverse, soi)) {
        check = true;
        cout << roiAdverse.first << ',' << roiAdverse.second << " check" << endl;
        mouvementsValides = getMouvementsValides(plateau->casePiece[roiAdverse.first][roiAdverse.second], roiAdverse.first, roiAdverse.second);
        if (mouvementsValides.size() == 0) {
            cout << "Stalemate";
        }
        case1 = posANomObj(roiAdverse.first, roiAdverse.second);
    }
    else {
        case1 = "";
    }
    case2 = "";
    turn = !turn;
}
/*
void echecs::GameWindow::testBouton() {
    ui.a1->setIcon(QIcon(":/GameWindow/images/TourNoir.png"));
    ui.a8->changerEtat(Case::pionBlanc);
    std::cout << "Bouton clicked;" << endl;
}*/


void front_end::GameWindow::syncPlateau() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto piece = plateau->casePiece[i][j];
            string position = posANomObj(i, j); ///===========3
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