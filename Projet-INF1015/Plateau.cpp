#include "Plateau.hpp"



back_end::Plateau::Plateau(back_end::Plateau::TypeJeu typeJeu) {
	switch (typeJeu) {
	case back_end::Plateau::normal:
		casePiece[0][0] = make_shared<Tour>(0, 0, Piece::blanc);
		casePiece[0][7] = make_shared<Tour>(0, 7, Piece::blanc);
		casePiece[0][1] = make_shared<Cavalier>(0, 1, Piece::blanc);
		casePiece[0][6] = make_shared<Cavalier>(0, 6, Piece::blanc);
		try {
			casePiece[0][4] = make_shared<Roi>(0, 4, Piece::blanc);
		}
		catch (ExceptionTropDeRois exception) {
			cout << exception.what() << endl;
			casePiece[7][4] = nullptr;
		}

		casePiece[7][0] = make_shared<Tour>(7, 0, Piece::noir);
		casePiece[7][7] = make_shared<Tour>(7, 7, Piece::noir);
		casePiece[7][1] = make_shared<Cavalier>(7, 1, Piece::noir);
		casePiece[7][6] = make_shared<Cavalier>(7, 6, Piece::noir);
		try {
			casePiece[7][4] = make_shared<Roi>(7, 4, Piece::noir);
		}
		catch (ExceptionTropDeRois exception) {
			cout << exception.what() << endl;
			casePiece[7][4] = nullptr;
		}
		break;
	default:
		break;
	}

}

back_end::Plateau::~Plateau() {
	//casePiece[0][0].reset();*
}
//Plateau::Plateau(){
//	for (int i = 0; i < DIM; ++i) {
//		for (int j = 0; j < DIM; ++j) {
//			casePiece[i][j] = nullptr;
//		}
//	}
//}
//
//void Plateau::initPlateau() {
//
//	for (int i = 0; i < DIM; ++i) {
//		ajouterPiece(make_shared<Pion>(make_pair(1, i), Couleur::blanc));
//		ajouterPiece(make_shared<Pion>(make_pair(6, i), Couleur::noir));
//	}
//}
//
//bool Plateau::estcaseOccupee(const pair<int, int>& position) const{
//	if (position.first < 0 || position.first >= DIM || position.second < 0 || position.second >= DIM) {
//		throw out_of_range("Hors plateau");
//	}
//	return casePiece[position.first][position.second] != nullptr;
//}
//
//void Plateau::bougerPiece(const pair<int, int>& depart, const pair<int, int>& destination) {
//	casePiece[destination.first][destination.second] = move(casePiece[depart.first][depart.second]); //inverser destinations-departs
//	//casePiece[depart.first][depart.second] = nullptr;
//}
//
//Piece* Plateau::trouverPiece(const pair<int, int>& position) const {
//	if (position.first >= 0 && position.first < 8 && position.second >= 0 && position.second < 8) {
//		return casePiece[position.first][position.second].get();
//	}
//	return nullptr;
//}
//
//void Plateau::ajouterPiece(const shared_ptr<Piece>& piece) {
//	auto position = piece->donnerPosition();
//	if (!estcaseOccupee(position)) {
//		casePiece[position.first][position.second] = piece;
//	}
//	//case est occupe
//}

