/**
* Tests unitaires pour le jeu échecs.
* \file   TestEchecs.cpp
* \author Song Ning Lan et Sheng He Ge
* \date   3 mai 2024
* Créé le 19 avril 2024
*/
#include "GameWindow.h"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

using namespace back_end;
using namespace front_end;
TEST(GameWindow, mouvementSimples) {
	GameWindow gameWindow;
	gameWindow.partieNormaleInit();
	auto& plateau = gameWindow.plateau->casePiece;

	EXPECT_EQ(plateau[0][7]->getCouleur(), Piece::noir);
	EXPECT_EQ(plateau[0][7]->getType(), Piece::Tour);

	gameWindow.jouerTour("h1", "h8");
	EXPECT_EQ(plateau[7][7], nullptr);
	EXPECT_EQ(plateau[0][7]->getCouleur(), Piece::blanc);
	EXPECT_EQ(plateau[0][7]->getType(), Piece::Tour);
	EXPECT_FALSE(plateau[0][7] == nullptr);

	gameWindow.jouerTour("g8", "f6");
	EXPECT_EQ(plateau[0][6], nullptr);
	EXPECT_EQ(plateau[2][5]->getCouleur(), Piece::noir);
	EXPECT_EQ(plateau[2][5]->getType(), Piece::Cavalier);
	EXPECT_FALSE(plateau[2][5] == nullptr);

	gameWindow.jouerTour("e1", "e2");
	EXPECT_EQ(plateau[7][4], nullptr);
	EXPECT_EQ(plateau[6][4]->getCouleur(), Piece::blanc);
	EXPECT_EQ(plateau[6][4]->getType(), Piece::Roi);
	EXPECT_FALSE(plateau[6][4] == nullptr);

}

TEST(GameWindow, blancStart) {
	GameWindow gameWindow;
	gameWindow.partieNormaleInit();
	auto& ui = gameWindow.ui;
	auto& plateau = gameWindow.plateau->casePiece;

	emit(ui.e8->clicked());
	EXPECT_EQ(ui.StatusLabel->text().toStdString(), "Attend ton tour mon enfant.");
	emit(ui.e7->clicked());
	EXPECT_EQ(ui.StatusLabel->text().toStdString(), "Case vide");

	EXPECT_EQ(plateau[1][4], nullptr);
	EXPECT_EQ(plateau[0][4]->getCouleur(), Piece::noir);
	EXPECT_EQ(plateau[0][4]->getType(), Piece::Roi);

	
	emit(ui.e1->clicked());
	EXPECT_EQ(ui.posLabel->text().toStdString(), "e1");
	emit(ui.e2->clicked());
	EXPECT_EQ(ui.posLabel->text().toStdString(), "e2");

	EXPECT_EQ(plateau[7][4], nullptr);
	EXPECT_EQ(plateau[6][4]->getCouleur(), Piece::blanc);
	EXPECT_EQ(plateau[6][4]->getType(), Piece::Roi);
}

TEST(GameWindow, mouvementsComplexes) {
	GameWindow gameWindow;
	gameWindow.partieNormaleInit();
	auto& ui = gameWindow.ui;
	auto& status = ui.StatusLabel;
	auto& pos = ui.posLabel;
	auto& plateau = gameWindow.plateau->casePiece;
	
	emit(ui.a1->clicked());
	emit(ui.a8->clicked());
	EXPECT_EQ(pos->text().toStdString(), "a8");
	EXPECT_EQ(plateau[7][0], nullptr);
	EXPECT_TRUE(plateau[0][0]->getCouleur() == Piece::blanc && plateau[0][0]->getType() == Piece::Tour);

	emit(ui.b8->clicked());
	emit(ui.b6->clicked());
	EXPECT_EQ(status->text().toStdString(), "Invalide.");
	EXPECT_EQ(plateau[2][1], nullptr);
	EXPECT_FALSE(plateau[0][1] == nullptr);
	emit(ui.a6->clicked());
	EXPECT_FALSE(plateau[2][0] == nullptr);

	emit(ui.a8->clicked());
	emit(ui.e8->clicked());
	EXPECT_EQ(status->text().toStdString(), "Game over");
	
}

TEST(GameWindow, echecRoi) {
	GameWindow gameWindow;
	gameWindow.partieNormaleInit();
	auto& ui = gameWindow.ui;
	auto& status = ui.StatusLabel;
	auto& plateau = gameWindow.plateau->casePiece;

	emit(ui.a1->clicked());
	emit(ui.a8->clicked());
	emit(ui.b8->clicked());
	emit(ui.a6->clicked());
	emit(ui.a8->clicked());
	emit(ui.a7->clicked());

	emit(ui.e8->clicked());
	emit(ui.e7->clicked());
	EXPECT_EQ(status->text().toStdString(), "Invalide.");
	EXPECT_EQ(plateau[1][4], nullptr);
	EXPECT_FALSE(plateau[0][4] == nullptr);

	emit(ui.d8->clicked());
	EXPECT_EQ(plateau[0][4], nullptr);
	EXPECT_FALSE(plateau[0][3] == nullptr);

	emit(ui.a7->clicked());
	emit(ui.d7->clicked());
	EXPECT_EQ(status->text().toStdString(), "0,3 check");
}

#endif