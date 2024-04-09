#pragma once



// classe abstraite
class Piece {
public:
	Piece() = default; //pour pouvoir initialiser le plateau
	Piece(int x, int y, bool couleur); //constructeur peut etre virtual
	//virtual void AbstractFunction() = 0; //exemple de methode abstraite
protected:

private:
	int posX = 0;
	int posY = 0;
	bool couleur = false; // pour eviter les warnings
	bool estMort = false; // probablement enlever apres
};