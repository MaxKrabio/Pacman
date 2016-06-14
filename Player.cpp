#include "Player.h"
#include "Size.h"
#include "Position.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPixmap>
int Player::direction = Qt::RightArrow;
Player::Player() :QObject()
{
    pos = new Position();
    pos->x = 300;
    pos->y = 300;
    dx = 0;
    dy = 0;
    startPosition = new Position();
    health = 3;
    speed = 2;
    direction = Qt::RightArrow;
    heroSprite = new QPixmap(":/res/resources/pacman.png");
}
void Player::setDirection (int direct) {
    direction = direct;
}
/*
bool Player::event(QEvent *event) {
    QKeyEvent *kEvent = static_cast<QKeyEvent *> (event);
    int key = kEvent->key();
    if (key < 37 || key > 40)
        return false;
    else direction = key;
}*/

void Player::move() {
    switch (direction) {
        case Qt::UpArrow :
                            dy = -speed;
                            break;
        case Qt::DownArrow :
                            dy = speed;
                            break;
        case Qt::LeftArrow :
                            dx = -speed;
                            break;
        case Qt::RightArrow :
                            dx = speed;
                            break;
    }

}

bool Player::alive() {
    return health > 0 ? true : false;
}

void Player::update () {
    move();
    pos->x += dx;
    pos->y += dy;
}
void Player::draw (QPainter *painter) {
 //   painter->setPen (QPen(Qt::red,Qt::SolidLine, 1, Qt::FlatCap));
    painter->setBrush (QBrush(Qt::red, Qt::SolidPattern));
    painter->drawRect (pos->x, pos->y, 30, 30);
}
Player::~Player () {
    delete heroSprite;
    delete pos;
    delete startPosition;
}
