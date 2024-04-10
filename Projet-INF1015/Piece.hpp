#pragma once
#include <utility>
enum class Couleur {
	vide,
	blanc,
	noir
};
// classe abstraite
class Piece {
public:
	Piece() = default; //pour pouvoir initialiser le plateau
	Piece(int x, int y, Couleur couleur); //constructeur peut etre virtual
	//bool operator==(const Piece& autre);
	//bool estoccupee();
	//virtual void AbstractFunction() = 0; //exemple de methode abstraite
	//bool estCaseValide();

protected:
	int posX = 8;
	int posY = 8;
	Couleur couleur = Couleur::vide;
private:
	 // pour eviter les warnings
	bool estMort = false; // probablement enlever apres
};