/**
* Classe qui tient le tableau représentant le plateau de jeu et qui respecte le RAII.
* \file   Plateau.hpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#pragma once
#include <vector>
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Roi.hpp"
#include "stdexcept"
#include <iostream>
#include <string>
using namespace std;


namespace back_end
{
	class Plateau {
	public:
		enum TypeJeu {
			normal,
			random1,
			random2,
		};
		static const int DIM = 8; // dimensions
		Plateau() = default;
		Plateau(TypeJeu typeJeu);
		~Plateau();

		shared_ptr<Piece> casePiece[DIM][DIM]; 
		
		
	protected:
	
	private:
		
	};
}