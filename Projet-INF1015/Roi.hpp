#pragma once
#include "Piece.hpp"
#include <exception>
#include <string>

class ExceptionTropDeRois : public exception { // classe custom pour un meilleur nom d'exception
		
public:
	using std::exception::exception;
	/*TropDeRois(const char* msg) : message(msg) {}
	const char* what() const throw() {
		return message.c_str();
	}*/
private:
	/*string message;*/
};

class Roi : public Piece {
public:
	Roi(int x, int y, Couleur couleur);
	~Roi();
protected:

private:
	static int nRois;
};