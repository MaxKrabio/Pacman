#ifndef GAME_H
#define GAME_H
#include <QThread>
#include <QPaintEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QScopedPointer>
#include <QWidget>
class Size;
class Player;
class Maze;
class Game
{
private:
    Size *size;
    QScopedPointer<Player> player;
    QScopedPointer<Maze> maze;
public:
    explicit Game(const Size &size);
    explicit Game(int w, int h);
    void draw(QPainter *painter);
    void update();
    bool isOver();
    void checkPlayerCollision();
    virtual ~Game();
};

#endif // GAME_H