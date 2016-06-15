#include "Player.h"
#include "Size.h"
#include "Maze.h"
#include "Position.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPixmap>
int Player::reqDirection = Qt::RightArrow;
int Player::direction = Qt::RightArrow;
Player::Player() :QObject()
{
    pos = new Position();
    pos->x = 99;
    pos->y = 44;
    dx = 0;
    dy = 0;
    startPosition = new Position();
    health = 3;
    speed = 2;
    direction = Qt::RightArrow;

    heroSprite = new QPixmap(":/res/resources/pacman.png");
}
void Player::setReqDirection (int direct) {
    reqDirection = direct;
}

/*bool Player::event(QEvent *event) {
    QKeyEvent *kEvent = static_cast<QKeyEvent *> (event);
    int key = kEvent->key();
    if (key < 37 || key > 40)
        return false;
    else reqDirection = key;
}
*/
bool Player::move(int rDirection) {

    bool state = false;
    switch (rDirection) {
        case Qt::Key_Up :
                            if ( pos->x  > 0 &&
                                Maze::checkPosition (pos->x -1,pos->y)) {
                                  pos->x += - 1;
                                  state = true;
                            }
                            break;
        case Qt::Key_Down :
                            if ( pos->x  < 259  &&
                                Maze::checkPosition (pos->x +1,pos->y)) {
                                    pos->x += 1;
                                    state = true;
                            }
                            break;
        case Qt::Key_Left :
                            if ( pos->y  > 0  &&
                                Maze::checkPosition (pos->x, pos->y -1)) {
                                    pos->y += - 1;
                                    state = true;
                            }
                            break;
        case Qt::Key_Right :
                            if ( pos->y < 227 &&
                                 Maze::checkPosition (pos->x, pos->y +1 )) {
                                     pos->y += 1;
                                     state = true;
                            }
                            break;
    }
    return state;
}

bool Player::alive() {
    return health > 0 ? true : false;
}

void Player::update () {
    if (move(reqDirection) == true)
        direction = reqDirection;
    else
        move(direction);/*
    if (Maze::checkPosition(pos->x + dx, pos->y + dy)){
        move(direction);
        pos->x += dx;
        pos->y += dy;
    } else {
                pos->x-=dx;
                pos->y -=dy;
    }*/
}
void Player::draw (QPainter *painter) {
    painter->setBrush (QBrush(Qt::red, Qt::SolidPattern));
    painter->drawRect (pos->y *2, pos->x *2, 30, 30);
}
Player::~Player () {
    delete heroSprite;
    delete pos;
    delete startPosition;
}
