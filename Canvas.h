#ifndef CANVAS_H
#define CANVAS_H
#include <QWidget>
#include "Game.h"
#include <QKeyEvent>
class Canvas : public QWidget
{
private:
    Game *game;
public:
    Canvas( Game *game, QWidget *parent = 0);
    void paintEvent (QPaintEvent *event);
    void keyPressEvent (QKeyEvent *);
};

#endif // CANVAS_H