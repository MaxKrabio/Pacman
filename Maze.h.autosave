#ifndef MAZE_H
#define MAZE_H
#include <Size.h>
#include <QObject>
class Maze : public QObject
{
    Q_OBJECT
private:
    Size size;
public:
    Maze(const Size &size);
    void draw(QPainter *painter);
    void update();
};

#endif // MAZE_H