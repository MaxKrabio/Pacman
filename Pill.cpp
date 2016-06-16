#include "Pill.h"
#include <QPainter>
Pill::Pill(int x, int y): pos(x, y) {}

void Pill::draw (QPainter *painter) {
    painter->setPen (QPen(Qt::darkYellow,1,Qt::SolidLine, Qt::FlatCap));
    painter->setBrush (Qt::darkYellow);
    painter->drawRect (pos.y * 2 - 10, pos.x * 2 + 20, 3, 3);
}
Position &Pill::getPostion() {
    return  pos;
}
