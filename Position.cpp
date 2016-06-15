#include "Position.h"

Position::Position()
{
  x = 0;
  y = 0;
}
Position::Position(int X, int Y) : x(X), y(Y)  {}
bool Position::operator == (const Position &pos) {
    if (this->x == pos.x && this->y == pos.y)
        return true;
}
