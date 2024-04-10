#pragma once
#include "Piece.hpp"



class Pion : public Piece {
public:
	Pion(int x, int y, Couleur couleur);
	bool estDepart();
	
protected:

private:
};