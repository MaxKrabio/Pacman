#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    double x;
    double y;
    Position();
    bool operator == (const Position &pos);
};

#endif // POSITION_H