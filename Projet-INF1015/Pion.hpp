#pragma once
#include "Piece.hpp"
#include "Plateau.hpp"


class Pion : public Piece {
public:
	Pion(pair<int, int> pos, Couleur couleur);
	vector<pair<int, int>> donnerMouvementsPossibles() const override;
	bool validationMouvement(const pair<int, int>& destination, const Plateau& plateau) const;
	vector<pair<int, int>> donnerMouvementsValides(const Plateau& plateau) const;
	
protected:

private:
};