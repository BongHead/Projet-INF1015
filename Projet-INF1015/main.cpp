﻿/**
* Programme qui implémente (partiellement) un jeu d'échecs.
* Le menu permet de commencer une partie et les boutons permettent
* de choisir le type de jeu. Les pièces sont implémentés avec vérification d'échec.
* 
* \file   main.cpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#include "GameWindow.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Plateau.hpp"
#include "Roi.hpp"

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}




int main(int argc, char* argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
    QApplication a(argc, argv);
	initialiserBibliothequeCours(argc, argv);

    front_end::GameWindow w;
    w.show();


	
    return a.exec();
}


// -fix array orientation logic done
// -check for valid moves (if valid move then consume turn and sync ui else restart turn and dont move anything)
// -check for illegal moves (especially king related)
// -check for check
// -end game if either king dies (I'll take care of the end screen)
