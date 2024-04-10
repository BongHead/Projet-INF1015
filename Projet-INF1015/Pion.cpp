#include "Pion.hpp"


Pion::Pion(int x, int y, Couleur couleur) : Piece(x, y, couleur) {

}

bool Pion::estDepart() {
	return (couleur == Couleur::noir && posY == 6) || (couleur == Couleur::blanc && posY == 1);
}
