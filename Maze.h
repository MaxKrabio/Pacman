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
     static QVector<QString> field;
public:
    Maze(const Size &size);
    Maze(int w, int h);
    void draw(QPainter *painter);
    void update();
    static inline bool checkPosition(int x, int y) {
            bool state = true;
            if (field[x / 2].at (y / 2) == '0')
                state = false;
            if (x <= 0 || x >= 456)
                state = false;
            else if (y < 0 || y > 520)
                state = false;
            return state;
    }
};

#endif // MAZE_H