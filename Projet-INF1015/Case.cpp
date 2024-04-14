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
		setIcon(QIcon());
		break;
	case tourBlanc:
		setIcon(QIcon());
		break;
	case cavalierBlanc:
		setIcon(QIcon());
		break;
	case fouBlanc:
		setIcon(QIcon());
		break;
	case reineBlanc:
		setIcon(QIcon());
		break;
	case roiBlanc:
		setIcon(QIcon());
		break;
	case pionNoir:
		setIcon(QIcon());
		break;
	case tourNoir:
		setIcon(QIcon());
		break;
	case cavalierNoir:
		setIcon(QIcon());
		break;
	case fouNoir:
		setIcon(QIcon());
		break;
	case reineNoir:
		setIcon(QIcon());
		break;
	case roiNoir:
		setIcon(QIcon());
		break;
	case vide:
		setIcon(QIcon());
		break;
	}
}
