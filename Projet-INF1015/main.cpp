#include "GameWindow.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Plateau.hpp"
#include "Pion.hpp"

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

	//bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    w.plateau.bougerPiece(make_pair<int, int>(1,1), make_pair(2,1));
    w.show();
    
    Pion pion10(make_pair(1, 0), Couleur::blanc);
    Pion pion20(make_pair(2, 1), Couleur::noir);
    w.plateau.ajouterPiece(make_shared<Pion>(pion10));
    w.plateau.ajouterPiece(make_shared<Pion>(pion20));


    cout << "pion (1,0) -> (3,0)" << ": " << pion10.validationMouvement({ 3,0 }, w.plateau) << endl;
    cout << "pion (1,0) -> (4,0)" << ": " << pion10.validationMouvement({ 4,0 }, w.plateau) << endl;
    cout << "pion (1,0) -> (2,0)" << ": " << pion10.validationMouvement({ 2,0 }, w.plateau) << endl;
    cout << "pion (1,0) -> (1,0)" << ": " << pion10.validationMouvement({ 1,0 }, w.plateau) << endl;
    cout << "pion (1,0) -> (2,1)" << ": " << pion10.validationMouvement({ 2,1 }, w.plateau) << endl;

    return a.exec();
}
