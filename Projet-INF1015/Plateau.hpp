#pragma once
#include <vector>
#include <memory>
#include "Piece.hpp"
#include <string>
using namespace std;


enum class TypePiece {
	Pion,
	Tour,
	Cavalier,
	Fou,
	Reine,
	Roi
};

class Plateau {
public:
	Plateau();
	vector<vector<shared_ptr<Piece>>> plateauJeu; //preferablement mettre des unique_ptr ou shared_ptr
	void ajouterPiece(TypePiece typePiece, int posX, int posY, bool couleur);
	bool caseOccupee(int posX, int posY); //possiblement private
	void bougerPiece(int posX, int posY);
protected:

private:
	static int nRois; //initialiser au constructeur
};