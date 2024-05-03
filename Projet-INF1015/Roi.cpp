/**
* Implémentation de la classe Roi
* \file   Roi.cpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#include "Roi.hpp"

int Roi::nRois = 0;

Roi::Roi(Couleur couleur) : Piece(couleur, Piece::Roi) {
	if (++nRois > 2) {
		throw ExceptionTropDeRois("Il ne peut y avoir plus de 2 rois.");
	}
}

Roi::~Roi() {
	--nRois;
}