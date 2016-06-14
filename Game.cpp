#include "Game.h"
#include "Maze.h"
#include "Player.h"
/*Game::Game(const Size &sz) : size(sz),
    player(new Player()), maze(new Maze(sz))
{
}*/
Game::Game(int w ,int h) :
    player(new Player()), maze(new Maze(w, h))
{
    this->size = new Size(w,h);
}
void Game::draw (QPainter *painter) {
    maze->draw(painter);
    player->draw (painter);
}
void Game::update () {
    maze->update();
    player->update ();
}
bool Game::isOver () {
  return !player->alive ();
}

Game::~Game() {
    delete size;
}
