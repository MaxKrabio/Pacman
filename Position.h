#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    int x;
    int y;
    Position();
    Position(int X , int Y);
    void operator=(const Position &position);
    bool operator==(const Position &pos);
    bool operator!=(const Position &pos);
};

#endif // POSITION_H