/**
* Implémentation de la classe Case
* \file   Case.cpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/

#include "Case.hpp"

void Case::changerEtat(EtatCase nouvelEtat) {
	if (etat != nouvelEtat) {
		etat = nouvelEtat;
		syncBitmap();
	}
}

void Case::syncBitmap() {
	switch (etat) {
	case pionBlanc:
		setIcon(QIcon(":/GameWindow/images/PionBlanc.png"));
		break;
	case tourBlanc:
		setIcon(QIcon(":/GameWindow/images/TourBlanc.png"));
		break;
	case cavalierBlanc:
		setIcon(QIcon(":/GameWindow/images/CavalierBlanc.png"));
		break;
	case fouBlanc:
		setIcon(QIcon(":/GameWindow/images/FouBlanc.png"));
		break;
	case reineBlanc:
		setIcon(QIcon(":/GameWindow/images/ReineBlanc.png"));
		break;
	case roiBlanc:
		setIcon(QIcon(":/GameWindow/images/RoiBlanc.png"));
		break;
	case pionNoir:
		setIcon(QIcon(":/GameWindow/images/PionNoir.png"));
		break;
	case tourNoir:
		setIcon(QIcon(":/GameWindow/images/TourNoir.png"));
		break;
	case cavalierNoir:
		setIcon(QIcon(":/GameWindow/images/CavalierNoir.png"));
		break;
	case fouNoir:
		setIcon(QIcon(":/GameWindow/images/FouNoir.png"));
		break;
	case reineNoir:
		setIcon(QIcon(":/GameWindow/images/ReineNoir.png"));
		break;
	case roiNoir:
		setIcon(QIcon(":/GameWindow/images/RoiNoir.png"));
		break;
	case vide:
		setIcon(QIcon());
		break;
	}
}
