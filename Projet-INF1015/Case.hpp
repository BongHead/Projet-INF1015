/**
* Classe représentant une case dans un plateau de jeu.
* \file   Case.hpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/

#pragma once
#include <QPushButton>
#include "Piece.hpp"
#include <memory>


class Case : public QPushButton{
	Q_OBJECT
public:
	enum EtatCase {
		pionBlanc,
		tourBlanc,
		cavalierBlanc,
		fouBlanc,
		reineBlanc,
		roiBlanc,
		pionNoir,
		tourNoir,
		cavalierNoir,
		fouNoir,
		reineNoir,
		roiNoir,
		vide,
	};
	Case(QWidget* parent = nullptr) : QPushButton(parent) {}
	void changerEtat(EtatCase nouvelEtat);
protected:

private:
	void syncBitmap();
	EtatCase etat = vide;
};



