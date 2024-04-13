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
	static const int DIM = 8; // dimensions
	Plateau();
	void initPlateau();

	void ajouterPiece(const shared_ptr<Piece>& piece);
	bool estcaseOccupee(const pair<int, int>& position) const; //possiblement private

	void bougerPiece(const pair<int, int>& from, const pair<int, int>& to); // aucune verification, doit etre fait au prealable
	
	Piece* trouverPiece(const pair<int, int>& position) const;
	
protected:

private:
	shared_ptr<Piece> casePiece[DIM][DIM];
};