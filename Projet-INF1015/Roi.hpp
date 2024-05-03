/**
* Classe représentant une pièce de type roi.
* \file   Roi.hpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#pragma once
#include "Piece.hpp"
#include <exception>
#include <string>

class ExceptionTropDeRois : public exception { // classe custom pour un meilleur nom d'exception
public:
	using std::exception::exception;
};

class Roi : public Piece {
public:
	Roi(Couleur couleur);
	~Roi();
protected:

private:
	static int nRois;
};