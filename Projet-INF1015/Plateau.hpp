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
	void ajouterPiece(TypePiece typePiece, pair<int, int> pos, Couleur couleur);
	bool caseOccupee(pair<int, int> pos); //possiblement private
	void bougerPiece(pair<int, int> pos);
protected:

private:
	
	//static int nRois; //initialiser au constructeur
	bool tour = false; //blanc = false
};