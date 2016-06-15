#include "Canvas.h"
#include "Player.h"
Canvas::Canvas(Game *sGame, QWidget *parent) :QWidget(parent), game(sGame) {}
void Canvas::paintEvent (QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    game->draw (&painter);
    this->setFocusPolicy (Qt::StrongFocus);
}

void Canvas::keyPressEvent (QKeyEvent *event)    {
      int key = event->key();
    if (key < Qt::Key_Left || key > Qt::Key_Down)
        return;
    else Player::setReqDirection (key);
}
