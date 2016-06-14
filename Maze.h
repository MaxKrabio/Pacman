#ifndef MAZE_H
#define MAZE_H
#include "Size.h"
#include <QObject>
#include <QString>
#include <QVector>
class QPainter;
class Maze
{
private:
    Size size;
    static QString field;
public:
    Maze(const Size &size);
    Maze(int w, int h);
    void draw(QPainter *painter);
    void update();
    static inline int charAt(int x, int y) {
            return (int)(field.at (x*y).toLatin1 ())- 48;
    }
};

#endif // MAZE_H