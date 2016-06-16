#ifndef ENEMY_H
#define ENEMY_H
#include <QStack>
#include "Position.h"
#include <QTimer>
class QPainter;
 class Enemy : public QObject
{
    Q_OBJECT
private:
    static Position *position;
    QVector< QVector<int> > Field;
    QStack<Position> pathToPacman;
    QStack<Position> pathToAngle;
    QTimer timer;

public slots:
     void  getPathToTarget ();
public:
    Enemy();
    void update();
    void draw(QPainter *painter);
    void move();
    static const Position & getPosition();
    static void initPosition(int x, int y);
    virtual ~Enemy();
};

#endif // ENEMY_H