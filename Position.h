#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    double x;
    double y;
    Position();
    Position(int X , int Y);
    bool operator == (const Position &pos);
};

#endif // POSITION_H