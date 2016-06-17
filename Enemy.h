#ifndef ENEMY_H
#define ENEMY_H
#include <QStack>
#include "Position.h"
#include <QTimer>
class QPainter;
class Maze;
 class Enemy : public QObject
{
    Q_OBJECT
private:
    Maze *maze;
    Position *position;
    Position *anglepos;
    QVector< QVector<int> > Field;
    QStack<Position> pathToPacman;
    QStack<Position> pathToAngle;
    QTimer timer;

public slots:
     void  getPathToTarget ();
     void  getPathToAngle();
     void fearON();
     void fearOFF();
public:
    Enemy(Maze *maze, QObject *parent = 0);
    void update();
    void draw(QPainter *painter);
    void move();
    void findPathToTarget(const Position *targetpos);
    const Position & getPosition();
    void initPosition(int x, int y);

    virtual ~Enemy();
};

#endif // ENEMY_H