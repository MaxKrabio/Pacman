#include "Position.h"

Position::Position()
{
  x = 0;
  y = 0;
}
bool Position::operator == (const Position &pos) {
    if (this->x == pos.x && this->y == pos.y)
        return true;
}
