#include "Pion.hpp"

Pion::Pion(pair<int, int> pos, Couleur couleur) : Piece(pos, couleur) {}

vector<pair<int, int>> Pion::donnerMouvementsPossibles() const {

    vector<pair<int, int>> mouvements;
    int debutblanc = 1;
    int debutnoir = 6;

    int direction = (couleur == Couleur::blanc) ? 1 : -1;

    pair<int, int> avancerPion(pos.first + direction, pos.second);
    mouvements.push_back(avancerPion);

    if ((couleur == Couleur::blanc && pos.first == debutblanc) || (couleur == Couleur::noir && pos.first == debutnoir)) {
        pair<int, int> avancerDepart(pos.first + 2 * direction, pos.second);
        mouvements.push_back(avancerDepart);
    }

    pair<int, int> captureGauche(pos.first + direction, pos.second - 1);
    pair<int, int> captureDroite(pos.first + direction, pos.second + 1);
    mouvements.push_back(captureGauche);
    mouvements.push_back(captureDroite);

    return mouvements;
}