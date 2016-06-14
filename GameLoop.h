#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <QThread>
class Game;
class Canvas;
class GameLoop : public QThread
{
    //Q_OBJECT
private:
    Game *game;
    Canvas *canvas;
public:
    GameLoop(Game *sGame, Canvas *sCanvas);
    void run ();
};

#endif // GAMELOOP_H