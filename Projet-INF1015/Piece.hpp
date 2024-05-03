/**
* Classe de base pour tous les types de pièces.
* \file   Piece.hpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#pragma once
#include <utility>
#include <vector>
using namespace std;

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
	enum Couleur {
		blanc,
		noir,
	};
	Piece() = default;
	Piece(Couleur couleur, Type type);

	Type getType() {
		return type_;
	} 
	Couleur getCouleur() {
		return couleur_;
	}

protected:
	Couleur couleur_;
	Type type_;
private:
};