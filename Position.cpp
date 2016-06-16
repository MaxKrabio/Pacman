#include "Position.h"

Position::Position()
{
  x = 0;
  y = 0;
}
void Position::operator=(const Position &position) {
    if (this != &position) {
        this->x = position.x;
        this->y = position.y;
    }
}

Position::Position(int X, int Y) : x(X), y(Y)  {}
bool Position::operator==(const Position &pos) {

    return  (this->x == pos.x && this->y == pos.y);
}
bool Position::operator!=(const Position &pos) {

    return  (this->x != pos.x || this->y != pos.y);
}

