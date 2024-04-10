#include "Plateau.hpp"
#include "Pion.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Fou.hpp"
#include "Reine.hpp"
#include "Roi.hpp"


Plateau::Plateau() : plateauJeu(8, vector<shared_ptr<Piece>>(8)) {

}

bool Plateau::caseOccupee(int posX, int posY) {
	return true;
}
void Plateau::bougerPiece(int posX, int posY) {

}

void Plateau::ajouterPiece(TypePiece typePiece, int posX, int posY, Couleur couleur) {
	if (caseOccupee(posX, posY)) {
		// ne pas permettre l'ajout
		return;
	}
	switch (typePiece) {
		case TypePiece::Pion:
			plateauJeu.at(posX).at(posY) = make_shared<Pion>(posX, posY, couleur);
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