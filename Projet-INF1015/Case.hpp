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
	//void setXY(int x, int y);
protected:

private:
	void syncBitmap();


	int posX=0; int posY=0;
	EtatCase etat = vide;
};



