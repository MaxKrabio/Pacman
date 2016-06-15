#ifndef MAZE_H
#define MAZE_H
#include "Size.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <Position.h>
#include <QTimer>
#include "Pill.h"
class QPainter;
class Position;
class Maze : public QObject
{
 Q_OBJECT
private:
     Size size;
     QTimer timer;
     QVector<QString> startField;
     static QVector<QString> field;
     std::list<Pill> startPills;
     std::list<Pill> pills;
     static int countPills;

public:
    Maze(const Size &size);
    Maze(int w, int h);
    void draw(QPainter *painter);
    void update();
    void removePill(const Position &position);
    void updateData();
    void initPills();
    bool levelComplete();
    void setPillsCount();
    int getPillsCount();
    static void initPlayerStartPosition ();
    static inline bool checkPosition(int x, int y) {
            return field[x].at (y) != '0';
    }
    virtual ~Maze();
public slots:
    void endAngryPacmanMode();
};

#endif // MAZE_H