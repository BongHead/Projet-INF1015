#pragma once
#include <vector>
#include <memory>
#include "Pion.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Fou.hpp"
#include "Reine.hpp"
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



		};
		static const int DIM = 8; // dimensions
		Plateau() = default;
		Plateau(TypeJeu typeJeu);
		~Plateau();
		//void initPlateau();
	
		//void ajouterPiece(const shared_ptr<Piece>& piece);
		//bool estcaseOccupee(const pair<int, int>& position) const; //possiblement private
	
		//void bougerPiece(const pair<int, int>& from, const pair<int, int>& to); // aucune verification, doit etre fait au prealable
	
		//Piece* trouverPiece(const pair<int, int>& position) const; //get la piece a position

		shared_ptr<Piece> casePiece[DIM][DIM]; //tempoeairement public
		
		
	protected:
	
	private:
		
	};
}