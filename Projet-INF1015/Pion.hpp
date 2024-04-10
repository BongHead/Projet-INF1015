#pragma once
#include "Piece.hpp"



class Pion : public Piece {
public:
	Pion(pair<int, int> pos, Couleur couleur);
	bool estDepart();
	
protected:

private:
};