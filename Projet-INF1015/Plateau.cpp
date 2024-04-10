#include "Plateau.hpp"
#include "Pion.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Fou.hpp"
#include "Reine.hpp"
#include "Roi.hpp"


Plateau::Plateau() : plateauJeu(8, vector<shared_ptr<Piece>>(8)) {

}

bool Plateau::caseOccupee(pair<int, int> pos) {
	return true;
}
void Plateau::bougerPiece(pair<int, int> pos) {

}

void Plateau::ajouterPiece(TypePiece typePiece, pair<int, int> pos, Couleur couleur) {
	if (caseOccupee(pos)) {
		// ne pas permettre l'ajout
		return;
	}
	switch (typePiece) {
		case TypePiece::Pion:
			//plateauJeu.at(pos) = make_shared<Pion>(pos, couleur);
			break;
		case TypePiece::Tour:
			break;
		case TypePiece::Cavalier:
			break;
		case TypePiece::Fou:
			break;
		case TypePiece::Reine:
			break;
		case TypePiece::Roi:
			// ne pas oublier de checker le nombre de rois
			
			break;
		default:
			break; //lancer une erreur de quelque sorte
	}
}