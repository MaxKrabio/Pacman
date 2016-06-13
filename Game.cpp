#include "Game.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),player(new Player()), maze(new Maze())
{
}