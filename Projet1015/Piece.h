#pragma once


class Piece {
public:
	virtual bool estMouvemenetValide(int a, int b) = 0;
protected:
	
private:
	int posX;
	int posY;
};