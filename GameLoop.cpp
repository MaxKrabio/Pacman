#include "GameLoop.h"
#include "Game.h"
#include "Canvas.h"
GameLoop::GameLoop(Game *sGame, Canvas *sCanvas) /*: game(sGame), canvas(sCanvas)*/
{
    game = sGame;
    canvas = sCanvas;

}

void GameLoop::run () {

    while (!game->isOver ()) {
         game->update ();
         canvas->update ();
         //canvas->repaint ();
         this->msleep (30);

    }
}
