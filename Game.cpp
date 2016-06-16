#include "Game.h"
#include "Maze.h"
#include "Player.h"
#include "Enemy.h"
/*Game::Game(const Size &sz) : size(sz),
    player(new Player()), maze(new Maze(sz))
{
}*/
int Game::delay;
long long Game::money;
Game::Game(int w ,int h) : QObject(),
    maze(new Maze()),player(new Player()), enemy(new Enemy()), size(new Size(w,h))
{
    maze->initPlayerStartPosition ();
    delay = 30;
    connect(this,&Game::roundRestart, this, &Game::startDataUpdate);
}
void Game::draw (QPainter *painter) {
    maze->draw(painter);
    enemy->draw(painter);
    player->draw (painter);
}
void Game::update () {
    maze->update();
    player->update ();
    enemy->update ();
    if (levelComplete ())
     emit roundRestart();
}
bool Game::isOver () {
  return !player->alive ();
}
void Game::setDelay (int Delay) {
    delay = Delay;
}
void Game::startDataUpdate() {
    money += 300;
    maze->updateData();
    player->setOnStartPosition();
}

bool Game::levelComplete() {
    return (maze->getPillsCount () == 0);
}
int Game::getDelay() {
    return delay;
}

void Game::addMoney (int kesh) {
    money += kesh;
}
Game::~Game() {
    delete size;
}
