#ifndef MAZE_H
#define MAZE_H
#include "Size.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <Position.h>
class QPainter;
class Position;
class Maze
{
private:
     Size size;
     static QVector<QString> field;
     std::list<Position> lstPills;
public:
    Maze(const Size &size);
    Maze(int w, int h);
    void draw(QPainter *painter);
    void update();
    void initPills();
    static inline bool checkPosition(int x, int y) {
            return field[x].at (y) != '0';
    }
};

#endif // MAZE_H