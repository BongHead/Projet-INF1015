/**
* Implémentation de la classe Plateau
* \file   Plateau.cpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/

#include "Plateau.hpp"


back_end::Plateau::Plateau(back_end::Plateau::TypeJeu typeJeu) {
	switch (typeJeu) {
	case back_end::Plateau::normal:
		casePiece[7][0] = make_shared<Tour>(Piece::blanc);
		casePiece[7][7] = make_shared<Tour>(Piece::blanc);
		casePiece[7][1] = make_shared<Cavalier>(Piece::blanc);
		casePiece[7][6] = make_shared<Cavalier>(Piece::blanc);
		try {
			casePiece[0][4] = make_shared<Roi>(Piece::noir);
		}
		catch (ExceptionTropDeRois &exception) {
			cout << exception.what() << endl;
			casePiece[0][4] = nullptr;
		}

		casePiece[0][0] = make_shared<Tour>(Piece::noir);
		casePiece[0][7] = make_shared<Tour>(Piece::noir);
		casePiece[0][1] = make_shared<Cavalier>(Piece::noir);
		casePiece[0][6] = make_shared<Cavalier>(Piece::noir);
		try {
			casePiece[7][4] = make_shared<Roi>(Piece::blanc);
		}
		catch (ExceptionTropDeRois &exception) {
			cout << exception.what() << endl;
			casePiece[7][4] = nullptr;
		}
		break;

	case back_end::Plateau::random1:
		casePiece[0][0] = make_shared<Tour>(Piece::blanc);
		casePiece[0][1] = make_shared<Cavalier>(Piece::blanc);
		casePiece[0][3] = make_shared<Cavalier>(Piece::blanc);
		casePiece[0][4] = make_shared<Tour>(Piece::blanc);
		try {
			casePiece[0][2] = make_shared<Roi>(Piece::blanc);
		}
		catch (ExceptionTropDeRois& exception) {
			cout << exception.what() << endl;
			casePiece[0][2] = nullptr;
		}

		casePiece[7][3] = make_shared<Tour>(Piece::noir);
		casePiece[7][4] = make_shared<Cavalier>(Piece::noir);
		casePiece[7][6] = make_shared<Cavalier>(Piece::noir);
		casePiece[7][7] = make_shared<Tour>(Piece::noir);
		try {
			casePiece[7][5] = make_shared<Roi>(Piece::noir);
		}
		catch (ExceptionTropDeRois& exception) {
			cout << exception.what() << endl;
			casePiece[7][5] = nullptr;
		}
		break;
	case back_end::Plateau::random2:
		casePiece[6][1] = make_shared<Tour>(Piece::blanc);
		casePiece[5][2] = make_shared<Cavalier>(Piece::blanc);
		casePiece[4][3] = make_shared<Cavalier>(Piece::blanc);
		casePiece[3][4] = make_shared<Tour>(Piece::blanc);
		try {
			casePiece[7][0] = make_shared<Roi>(Piece::blanc);
		}
		catch (ExceptionTropDeRois& exception) {
			cout << exception.what() << endl;
			casePiece[7][0] = nullptr;
		}

		casePiece[2][6] = make_shared<Tour>(Piece::noir);
		casePiece[3][5] = make_shared<Cavalier>(Piece::noir);
		casePiece[4][4] = make_shared<Cavalier>(Piece::noir);
		casePiece[5][3] = make_shared<Tour>(Piece::noir);
		try {
			casePiece[1][7] = make_shared<Roi>(Piece::noir);
		}
		catch (ExceptionTropDeRois& exception) {
			cout << exception.what() << endl;
			casePiece[1][7] = nullptr;
		}
		break;
	default:
		break;
	}

}

back_end::Plateau::~Plateau() { }


