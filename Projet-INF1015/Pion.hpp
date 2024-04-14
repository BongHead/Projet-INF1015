#pragma once
#include "Piece.hpp"
#include "Plateau.hpp"


class Pion : public Piece {
public:
	Pion(pair<int, int> pos, Couleur couleur);
	vector<pair<int, int>> donnerMouvementsPossibles() const override;	//mouvements possibles en prenant compte de la dimension
	bool validationMouvement(const pair<int, int>& destination, const Plateau& plateau) const;	//mouvements possibles en prenant compte de l'etat de l'echiquier
	vector<pair<int, int>> donnerMouvementsValides(const Plateau& plateau) const; //retourne une liste des mouvements valides
	
protected:

private:
};