#include "GameWindow.h"

echecs::GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent), plateau()
{
    ui.setupUi(this);


    //==============================
    ui.CommencerButton->setVisible(false);
    ui.QuitterButton->setVisible(false);
    ui.GameTitle->setVisible(false);
    //==============================

    assignerPos();


    QPixmap pix(":/GameWindow/images/Board.png");
    int x = ui.BoardImg->width();
    int y = ui.BoardImg->height();
    ui.BoardImg->setPixmap(pix.scaled(x,y,Qt::KeepAspectRatio));
    

}

echecs::GameWindow::~GameWindow()
{}

void echecs::GameWindow::commencerButton() {
    ui.GameTitle->setVisible(false);
    ui.gameHider->setVisible(false);
    ui.CommencerButton->setVisible(false);
    ui.QuitterButton->setVisible(false);
}

void echecs::GameWindow::quitterButton() {
    auto reply = QMessageBox::question(this, "Quitter?", "\"Chess is... no different from Tic-Tac-Toe.\" - 1/2 Kohaku", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
        close();
}
/*
void echecs::GameWindow::testBouton() {
    ui.a1->setIcon(QIcon(":/GameWindow/images/TourNoir.png"));
    ui.a8->changerEtat(Case::pionBlanc);
    std::cout << "Bouton clicked;" << endl;
}*/

void echecs::GameWindow::assignerPos() {
    ui.a1->setXY(0,0);
    ui.b1->setXY(1,0);
    ui.c1->setXY(2,0);
    ui.d1->setXY(3,0);
    ui.e1->setXY(4,0);
    ui.f1->setXY(5,0);
    ui.g1->setXY(6,0);
    ui.h1->setXY(7,0);

    ui.a2->setXY(0,1);
    ui.b2->setXY(1,1);
    ui.c2->setXY(2,1);
    ui.d2->setXY(3,1);
    ui.e2->setXY(4,1);
    ui.f2->setXY(5,1);
    ui.g2->setXY(6,1);
    ui.h2->setXY(7,1);

    ui.a3->setXY(0,2);
    ui.b3->setXY(1,2);
    ui.c3->setXY(2,2);
    ui.d3->setXY(3,2);
    ui.e3->setXY(4,2);
    ui.f3->setXY(5,2);
    ui.g3->setXY(6,2);
    ui.h3->setXY(7,2);

    ui.a4->setXY(0,3);
    ui.b4->setXY(1,3);
    ui.c4->setXY(2,3);
    ui.d4->setXY(3,3);
    ui.e4->setXY(4,3);
    ui.f4->setXY(5,3);
    ui.g4->setXY(6,3);
    ui.h4->setXY(7,3);

    ui.a5->setXY(0,4);
    ui.b5->setXY(1,4);
    ui.c5->setXY(2,4);
    ui.d5->setXY(3,4);
    ui.e5->setXY(4,4);
    ui.f5->setXY(5,4);
    ui.g5->setXY(6,4);
    ui.h5->setXY(7,4);

    ui.a6->setXY(0,7);
    ui.b6->setXY(1,7);
    ui.c6->setXY(2,7);
    ui.d6->setXY(3,7);
    ui.e6->setXY(4,7);
    ui.f6->setXY(5,7);
    ui.g6->setXY(6,7);
    ui.h6->setXY(7,7);

    ui.a7->setXY(0,6);
    ui.b7->setXY(1,6);
    ui.c7->setXY(2,6);
    ui.d7->setXY(3,6);
    ui.e7->setXY(4,6);
    ui.f7->setXY(5,6);
    ui.g7->setXY(6,6);
    ui.h7->setXY(7,6);

    ui.a8->setXY(0,7);
    ui.b8->setXY(1,7);
    ui.c8->setXY(2,7);
    ui.d8->setXY(3,7);
    ui.e8->setXY(4,7);
    ui.f8->setXY(5,7);
    ui.g8->setXY(6,7);
    ui.h8->setXY(7,7);

}

void echecs::GameWindow::partieNormaleInit() {
    //reset game
    ui.a1->changerEtat(Case::tourBlanc);
    ui.b1->changerEtat(Case::cavalierBlanc);
    ui.c1->changerEtat(Case::fouBlanc);
    ui.d1->changerEtat(Case::reineBlanc);
    ui.e1->changerEtat(Case::roiBlanc);
    ui.f1->changerEtat(Case::fouBlanc);
    ui.g1->changerEtat(Case::cavalierBlanc);
    ui.h1->changerEtat(Case::tourBlanc);
    ui.a2->changerEtat(Case::pionBlanc);
    ui.b2->changerEtat(Case::pionBlanc);
    ui.c2->changerEtat(Case::pionBlanc);
    ui.d2->changerEtat(Case::pionBlanc);
    ui.e2->changerEtat(Case::pionBlanc);
    ui.f2->changerEtat(Case::pionBlanc);
    ui.g2->changerEtat(Case::pionBlanc);
    ui.h2->changerEtat(Case::pionBlanc);

    ui.a8->changerEtat(Case::tourNoir);
    ui.b8->changerEtat(Case::cavalierNoir);
    ui.c8->changerEtat(Case::fouNoir);
    ui.d8->changerEtat(Case::reineNoir);
    ui.e8->changerEtat(Case::roiNoir);
    ui.f8->changerEtat(Case::fouNoir);
    ui.g8->changerEtat(Case::cavalierNoir);
    ui.h8->changerEtat(Case::tourNoir);
    ui.a7->changerEtat(Case::pionNoir);
    ui.b7->changerEtat(Case::pionNoir);
    ui.c7->changerEtat(Case::pionNoir);
    ui.d7->changerEtat(Case::pionNoir);
    ui.e7->changerEtat(Case::pionNoir);
    ui.f7->changerEtat(Case::pionNoir);
    ui.g7->changerEtat(Case::pionNoir);
    ui.h7->changerEtat(Case::pionNoir);

}