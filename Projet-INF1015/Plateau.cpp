#include "Plateau.hpp"
#include "Pion.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Fou.hpp"
#include "Reine.hpp"
#include "Roi.hpp"
#include "stdexcept"


Plateau::Plateau(){
	initPlateau();
}

void Plateau::initPlateau() {
	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {
			casePiece[i][j] = nullptr;
		}
	}

	for (int i = 0; i < DIM; ++i) {
		ajouterPiece(make_shared<Pion>(make_pair(1, i), Couleur::blanc), make_pair(1, i));
		ajouterPiece(make_shared<Pion>(make_pair(6, i), Couleur::noir), make_pair(6, i));
	}
}

bool Plateau::estcaseOccupee(const pair<int, int>& position) const{
	if (position.first < 0 || position.first >= DIM || position.second < 0 || position.second >= DIM) {
		throw out_of_range("Hors plateau");
	}
	return casePiece[position.first][position.second] != nullptr;
}

void Plateau::bougerPiece(const pair<int, int>& depart, const pair<int, int>& destination) {
	casePiece[destination.first][destination.second] = move(casePiece[depart.first][depart.second]); //inverser destinations-departs
	//casePiece[depart.first][depart.second] = nullptr;
}

void Plateau::ajouterPiece(const shared_ptr<Piece>& piece, const pair<int, int>& position) {
	if (!estcaseOccupee(position)) {
		casePiece[position.first][position.second] = piece;
	}
	//case est occupe
}