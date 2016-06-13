#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>
#include<QPainter>
class Position;
class Size;
class Player : public QObject
{
 Q_OBJECT
private:
        Position pos;
public:
    Player(QObject *parent = 0);
    void draw(QPainter *painter);
    void update();
};

#endif // PLAYER_H