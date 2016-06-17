#include "Player.h"
#include "Size.h"
#include "Maze.h"
#include "Position.h"
#include <QPainter>
#include <QKeyEvent>
#include <QPixmap>
int Player::reqDirection = Qt::RightArrow;
int Player::direction = Qt::RightArrow;
Position* Player::pos;
Position* Player::startPosition;
//Position* Player::startPosition;
Player::Player(Maze * maze, QObject *parent) :QObject(parent)
{
    pos = new Position();
    this->maze = maze;
    //set player start position
    maze->initPlayerStartPosition(pos);
    dx = 0;
    dy = 0;
    startPosition = new Position();
    health = 3;
    direction = Qt::RightArrow;
    heroSprite = new QPixmap(":/res/resources/pacman.png");
}
void Player::setReqDirection (int direct) {
    reqDirection = direct;
}
bool Player::move(int rDirection) {

    bool state = false;
    switch (rDirection) {
        case Qt::Key_Up :
                            if ( pos->x  > 0 &&
                                maze->checkPosition (pos->x -1,pos->y)) {
                                  pos->x += - 1;
                                  state = true;
                            }
                            break;
        case Qt::Key_Down :
                            if ( pos->x  < 259  &&
                                maze->checkPosition (pos->x +1,pos->y)) {
                                    pos->x += 1;
                                    state = true;
                            }
                            break;
        case Qt::Key_Left :
                            if (pos->y - 1 == 0 &&
                                maze->checkPosition (pos->x, pos->y -1)) {
                                    pos->y = 227;
                                    state = true;
                            }  else if ( pos->y  > 0  &&
                                    maze->checkPosition (pos->x, pos->y -1)) {
                                    pos->y += - 1;
                                    state = true;
                            }
                            break;
        case Qt::Key_Right :
                             if ( pos->y + 1 == 227 &&
                                 maze->checkPosition (pos->x, pos->y +1 )) {
                                     pos->y = 1;
                                     state = true;
                            }  else if ( pos->y < 227 &&
                                    maze->checkPosition (pos->x, pos->y +1 )) {
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
const Position * Player::playerPosition () {
    return pos;
}

void Player::update () {
    if (move(reqDirection) == true)
        direction = reqDirection;
    else
        move(direction);
}
void Player::draw (QPainter *painter) {
    painter->setBrush (QBrush(Qt::red, Qt::SolidPattern));
    painter->drawRect (pos->y *2 - 15, pos->x * 2 - 15 , 30, 30);
}
void Player::setOnStartPosition() {
    pos = startPosition;
}

void Player::initPosition (int x, int y) {
    pos->x = x;
    pos->y = y;
    startPosition = pos;
}

Player::~Player () {
    delete heroSprite;
    delete pos;
    delete startPosition;
}
