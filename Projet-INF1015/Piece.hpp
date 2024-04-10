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
	Piece() = default; //pour pouvoir initialiser le plateau
	Piece(pair<int, int> pos, Couleur couleur); //constructeur peut etre virtual

	Couleur donnerCouleur();

	void mettrePosition(pair<int, int> newPos);

	pair<int, int> donnerPosition();

	vector<pair<int, int>> donnerMouvementsPossibles() { return mouvementsPossible; };

	Piece(const Piece& piece);
	~Piece() {};

protected:
	pair<int, int> pos;
	Couleur couleur = Couleur::vide;
	vector<pair<int, int>> mouvementsPossible;
};