#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent), plateau()
{
    ui.setupUi(this);

    QPixmap pix(":/GameWindow/images/Board.png");
    int x = ui.BoardImg->width();
    int y = ui.BoardImg->height();
    ui.BoardImg->setPixmap(pix.scaled(x,y,Qt::KeepAspectRatio));
    

}

GameWindow::~GameWindow()
{}

void GameWindow::commencerButton() {
    ui.GameTitle->setVisible(false);
    ui.gameHider->setVisible(false);
    ui.CommencerButton->setVisible(false);
    ui.QuitterButton->setVisible(false);
}

void GameWindow::quitterButton() {
    auto reply = QMessageBox::question(this, "Quitter?", "\"Chess is... no different from Tic-Tac-Toe.\" - 1/2 Kohaku", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
        close();
}

void GameWindow::testBouton() {
    ui.a1->setIcon(QIcon(":/GameWindow/images/TourNoir.png"));
    //ui.a1->setIcon(QIcon());
    std::cout << "Bouton clicked;" << endl;
}