#include "Pion.hpp"

Pion::Pion(pair<int, int> pos, Couleur couleur) : Piece(pos, couleur) {}

vector<pair<int, int>> Pion::donnerMouvementsPossibles() const {

    vector<pair<int, int>> mouvements;
    int debutblanc = 1;
    int debutnoir = 6;

    int direction = (couleur == Couleur::blanc) ? 1 : -1;

    pair<int, int> avancerPion(pos.first + direction, pos.second);
    if (avancerPion.first >= 0 && avancerPion.first < 8)
        mouvements.push_back(avancerPion);

    if ((couleur == Couleur::blanc && pos.first == debutblanc) || (couleur == Couleur::noir && pos.first == debutnoir)) {
        pair<int, int> avancerDepart(pos.first + 2 * direction, pos.second);
        mouvements.push_back(avancerDepart);
    }

    pair<int, int> captureGauche(pos.first + direction, pos.second - 1);
    pair<int, int> captureDroite(pos.first + direction, pos.second + 1);
    if (captureGauche.first >= 0 && captureGauche.second < 8 && captureGauche.second > 0)
        mouvements.push_back(captureGauche);
    if (captureDroite.first >= 0 && captureDroite.second < 8 && captureDroite.second > 0)
        mouvements.push_back(captureDroite);

    return mouvements;
}

bool Pion::validationMouvement(const pair<int, int>& destination, const Plateau& plateau) const{
    int direction = (couleur == Couleur::blanc) ? 1 : -1; 
    int rangeeDepart = (couleur == Couleur::blanc) ? 1 : 6;

    if (destination.second == pos.second) {
        if ((destination.first - pos.first) == direction) { 
            return !plateau.estcaseOccupee(destination);
        }
        if ((pos.first == rangeeDepart) && ((destination.first - pos.first) == 2 * direction)) {
            
            return !plateau.estcaseOccupee(destination) && !plateau.estcaseOccupee({pos.first + direction, pos.second});
        }
    }

    //capture
    if (abs(destination.second - pos.second) == 1 && (destination.first - pos.first) == direction) {
        if (!plateau.estcaseOccupee(destination)) {
            return false; 
        }

        Piece* pieceCaseDestination = plateau.trouverPiece(destination);    // trouve la couleur de la piece en diagonal
        if (pieceCaseDestination->donnerCouleur() != this->couleur) {
            return true;
        }
    }

    return false;
}

vector<pair<int, int>> Pion::donnerMouvementsValides(const Plateau& plateau) const{
    vector<pair<int, int>> mouvements = donnerMouvementsPossibles();
    vector<pair<int, int>> mouvementsValides;

    for (const auto& move : mouvements) {
        if (validationMouvement(move, plateau)) {
            mouvementsValides.push_back(move);
        }
    }

    return mouvementsValides;
}