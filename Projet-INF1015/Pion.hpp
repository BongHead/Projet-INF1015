#pragma once
#include "Piece.hpp"
#include "Plateau.hpp"


class Pion : public Piece {
public:
	Pion(pair<int, int> pos, Couleur couleur);
	vector<pair<int, int>> donnerMouvementsPossibles() const override;
	bool validationMouvement(const pair<int, int>& destination, const Plateau& plateau);
	
protected:

private:
};