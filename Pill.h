#ifndef PILL_H
#define PILL_H
#include "Position.h"
class QPainter;
class Pill
{
protected:
    Position pos;
public:
    Pill(int x, int y);
    virtual void draw(QPainter *painter);
};

#endif // PILL_H