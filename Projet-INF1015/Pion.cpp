#include "Pion.hpp"


Pion::Pion(pair<int, int> pos, Couleur couleur) : Piece(pos, couleur) {

}

bool Pion::estDepart() {
	return (couleur == Couleur::noir && pos.second == 7) || (couleur == Couleur::blanc && pos.second == 2);
}
