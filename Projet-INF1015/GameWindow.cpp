#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QPixmap pix(":/GameWindow/images/Board.png");
    int x = ui.BoardImg->width();
    int y = ui.BoardImg->height();
    ui.BoardImg->setPixmap(pix.scaled(x,y,Qt::KeepAspectRatio));
}

GameWindow::~GameWindow()
{}


