#include "Piece.hpp"


Piece::Piece(pair<int, int> pos, Couleur couleur) : pos(pos), couleur(couleur) {

}

Couleur Piece::donnerCouleur() { return couleur; };
void Piece::mettrePosition(pair<int, int> newPos) { pos = newPos; };
pair<int, int> Piece::donnerPosition() { return pos; };
