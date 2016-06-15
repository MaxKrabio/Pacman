#ifndef POWERPILL_H
#define POWERPILL_H
#include "Pill.h"
class QPainter;
class PowerPill : public Pill
{
public:
    PowerPill(int x, int y);
    virtual void draw(QPainter *painter);
};

#endif // POWERPILL_H
