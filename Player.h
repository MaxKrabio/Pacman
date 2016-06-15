#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>
#include <QKeyEvent>
class Position;
class Size;
class QPainter;
class QPixmap;
class Player : public QObject
{
 Q_OBJECT
private:
        Position *startPosition;
        Position *pos;
        QPixmap  *heroSprite;
        int health;
        int speed;
        static int reqDirection;
        static int direction;
        int dx;
        int dy;
public:
    explicit Player();
    void draw(QPainter *painter);
    void update();
    bool move(int rDirection);
    bool alive();
//    bool event (QEvent *Event);
    static void setReqDirection(int direct);
    const Position & getPosition();
    ~Player();
};

#endif // PLAYER_H