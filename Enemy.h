#ifndef ENEMY_H
#define ENEMY_H
#include <QStack>
#include "Position.h"
class QPainter;
 class Enemy
{
private:
    static Position *position;
    QVector<QString> Field;
    QStack<Position> pathToPacman;
    QStack<Position> pathToAngle;
//public slots:

public:
    Enemy();
    void update();
    void draw(QPainter *painter);
    void getPathToTarget ();
    void move();
    static const Position & getPosition();
    static void initPosition(int x, int y);
    ~Enemy();
};

#endif // ENEMY_H