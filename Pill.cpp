#include "Pill.h"
#include <QPainter>
Pill::Pill(int x, int y): pos(x, y) {}

void Pill::draw (QPainter *painter) {
    painter->setPen (QPen(Qt::darkYellow,3,Qt::SolidLine, Qt::FlatCap));
    painter->setBrush (Qt::darkYellow);
    painter->drawEllipse (pos.y * 2, pos.x * 2, 3, 3);
}
