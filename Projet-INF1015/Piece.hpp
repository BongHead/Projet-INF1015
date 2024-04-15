#pragma once
#include <utility>
#include <vector>
using namespace std;

enum class Couleur {
	vide,
	blanc,
	noir,
};

// classe abstraite
class Piece {
public:
	enum Type {
		Pion,
		Tour,
		Cavalier,
		Fou,
		Reine,
		Roi,
	};
	Piece() = default; //pour pouvoir initialiser le plateau
	Piece(pair<int, int> pos, Couleur couleur); //constructeur peut etre virtual
	Type getType() { return type; }
	Couleur donnerCouleur() const;

	void mettrePosition(pair<int, int> newPos);

	pair<int, int> donnerPosition() const;

	virtual vector<pair<int, int>> donnerMouvementsPossibles() const;

	Piece(const Piece& piece);
	virtual ~Piece() {};

protected:
	pair<int, int> pos;
	Couleur couleur = Couleur::vide;
	
	vector<pair<int, int>> mouvementsPossible;
	Type type;

};