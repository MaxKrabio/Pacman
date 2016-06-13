#ifndef GAME_H
#define GAME_H
#include <QThread>
#include <QPaintEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QScopedPointer>
class Game : virtual public QThread, public QWidget
{
    Q_OBJECT
private:
    Size size;
    Position pos;
    QScopedPointer<Player> player;
    QScopedPointer<Maze> maze;
public:
    explicit Game(QWidget *parent);
    void paintEvent(QPaintEvent * event);
    void g_update();
    void gameLoop();
    void run();
    virtual ~Game();
};

#endif // GAME_H