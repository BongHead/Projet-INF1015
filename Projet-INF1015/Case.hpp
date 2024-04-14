#pragma once
#include "Piece.hpp"
#include <memory>
#include <QPushButton>

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

	shared_ptr<Piece> piece;

	void changerEtat(EtatCase nouvelEtat);
	
protected:

private:
	void syncBitmap();


	int posX=0; int posY=0;
	EtatCase etat = vide;
};



