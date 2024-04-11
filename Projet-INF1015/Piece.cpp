#include "Piece.hpp"


Piece::Piece(pair<int, int> pos, Couleur couleur) : pos(pos), couleur(couleur) {}

Piece::Piece(const Piece& piece) : pos(piece.pos), couleur(piece.couleur), mouvementsPossible(piece.mouvementsPossible) {}

Couleur Piece::donnerCouleur() const { return couleur; };
void Piece::mettrePosition(pair<int, int> newPos) { pos = newPos; };
pair<int, int> Piece::donnerPosition() const { return pos; };
vector<pair<int, int>> Piece::donnerMouvementsPossibles() const { return mouvementsPossible; };