#ifndef GAME_H
#define GAME_H
#include <QThread>
#include <QPaintEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QScopedPointer>
#include <QWidget>
class Size;
class Player;
class Maze;
class Enemy;
class Game : public QObject
{
    Q_OBJECT
private:
    QScopedPointer<Player> player;
    QScopedPointer<Enemy> enemy;
    QScopedPointer<Maze> maze;

    Size *size;
    static int delay;
    static long long money;

signals:
    void roundRestart();
public slots:
    void startDataUpdate();
public:
    explicit Game(const Size &size);
    explicit Game(int w, int h);
    void draw(QPainter *painter);
    void update();
    bool isOver();
    static void addMoney(int kesh);
    bool levelComplete();
    static void setDelay(int Delay);
    int getDelay();
    void checkPlayerCollision();
    virtual ~Game();
};

#endif // GAME_H