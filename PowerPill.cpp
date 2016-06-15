#include "PowerPill.h"
#include "Pill.h"
#include <QPainter>
PowerPill::PowerPill(int x, int y) : Pill(x, y) {}

void PowerPill::draw (QPainter *painter) {
    painter->setPen (QPen(Qt::darkYellow,3,Qt::SolidLine, Qt::FlatCap));
    painter->setBrush (Qt::darkYellow);
    painter->drawEllipse (pos.y *2, pos.x * 2, 6, 6);
}
