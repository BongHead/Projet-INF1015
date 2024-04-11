#pragma once
#include "Piece.hpp"



class Pion : public Piece {
public:
	Pion(pair<int, int> pos, Couleur couleur);
	vector<pair<int, int>> donnerMouvementsPossibles(const Plateau& plateau) const override;
	
protected:

private:
};