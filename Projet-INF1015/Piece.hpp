#pragma once
#include <utility>
#include <vector>
using namespace std;

// classe abstraite
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
	Piece(int x, int y, Couleur couleur, Type type);

	Type getType() {
		return type_;
	} 
	Couleur getCouleur() {
		return couleur_;
	}
	
	//Piece(pair<int, int> pos, Couleur couleur, Type type); //constructeur peut etre virtual
	/*Type getType() { return type; }
	Couleur donnerCouleur() const;

	void mettrePosition(pair<int, int> newPos);

	pair<int, int> donnerPosition() const;

	virtual vector<pair<int, int>> donnerMouvementsPossibles() const;

	Piece(const Piece& piece);
	virtual ~Piece() {};*/

protected:
	pair<int, int> pos_;
	Couleur couleur_;
	//vector<pair<int, int>> mouvementsPossible;
	Type type_;

private:

};