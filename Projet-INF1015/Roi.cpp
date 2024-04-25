#include "Roi.hpp"

int Roi::nRois = 0;

Roi::Roi(int x, int y, Couleur couleur) : Piece(x, y , couleur, Piece::Roi) {
	if (++nRois > 2) {
		throw ExceptionTropDeRois("Il ne peut y avoir plus de 2 rois.");
	}
}

Roi::~Roi() {
	--nRois;
}