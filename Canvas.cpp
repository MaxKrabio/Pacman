#include "Canvas.h"
#include "Player.h"
Canvas::Canvas(Game *sGame, QWidget *parent) :QWidget(parent), game(sGame) {}
void Canvas::paintEvent (QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    game->draw (&painter);
}

void Canvas::keyPressEvent (QKeyEvent *event) {
      int key = event->key();
    if (key < 37 || key > 40)
        return;
    else Player::setDirection (key);
}
