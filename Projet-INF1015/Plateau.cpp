#include "Plateau.hpp"
#include "Pion.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Fou.hpp"
#include "Reine.hpp"
#include "Roi.hpp"
#include "stdexcept"


Plateau::Plateau(){
	for (int i = 0; i < DIM; ++i) {
		for (int j = 0; j < DIM; ++j) {
			casePiece[i][j] = nullptr;
		}
	}
}

void Plateau::initPlateau() {

	for (int i = 0; i < DIM; ++i) {
		ajouterPiece(make_shared<Pion>(make_pair(1, i), Couleur::blanc));
		ajouterPiece(make_shared<Pion>(make_pair(6, i), Couleur::noir));
	}
}

bool Plateau::estcaseOccupee(const pair<int, int>& position) const{
	if (position.first < 0 || position.first >= DIM || position.second < 0 || position.second >= DIM) {
		throw out_of_range("Hors plateau");
	}
	return casePiece[position.first][position.second] != nullptr;
}

void Plateau::bougerPiece(const pair<int, int>& depart, const pair<int, int>& destination) {
	casePiece[depart.first][depart.second] = move(casePiece[destination.first][destination.second]);
}

void Plateau::ajouterPiece(const shared_ptr<Piece>& piece) {
	auto position = piece->donnerPosition();
	if (!estcaseOccupee(position)) {
		casePiece[position.first][position.second] = piece;
		return;
	}
	return; //case est occupe
}