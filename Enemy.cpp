#include "Enemy.h"
#include "Player.h"
#include "Maze.h"
#include <QPainter>
#include <QStack>
#include "Size.h"
Enemy::Enemy(Maze *maze, QObject *parent) : QObject(parent), timer(this)
 {
    this->maze = maze;
    position = new Position();
    anglepos = new Position(0,0);
     // set enemy start position
    maze->initEnemyStartPosition (position);
    connect(&timer,&QTimer::timeout,this,&Enemy::getPathToTarget);
    connect(maze, &Maze::angryPacmanModeON, this, &Enemy::fearON);
    connect(maze, &Maze::angryPacmanModeOFF, this, &Enemy::fearOFF);
    getPathToTarget ();

}
void Enemy::draw (QPainter *painter) {
    painter->setBrush (QBrush(Qt::blue, Qt::SolidPattern));
    painter->drawRect (position->y *2, position->x *2, 30, 30);
}
const Position & Enemy::getPosition () {
    return *position;
}
void Enemy::initPosition (int x, int y) {
    position->x = x;
    position->y = y;
}
void Enemy::update () {
    //getPathToTarget ();
    move();
}
void Enemy::move() {
if (!pathToPacman.isEmpty ()) {
    *position = pathToPacman.back ();
    pathToPacman.pop_back ();
    }
}
void Enemy::fearON() {
    disconnect(&timer, &QTimer::timeout, this, &Enemy::getPathToTarget);
    connect(&timer, &QTimer::timeout, this, &Enemy::getPathToAngle);
    getPathToAngle ();
    move();
}
void Enemy::fearOFF() {
    disconnect(&timer, &QTimer::timeout, this, &Enemy::getPathToAngle);
    connect(&timer, &QTimer::timeout, this, &Enemy::getPathToTarget);
    getPathToTarget ();
    move();
}

void Enemy::getPathToAngle() {
     findPathToTarget(anglepos);
     timer.start(1000);
}
void Enemy::getPathToTarget () {
     findPathToTarget(Player::playerPosition ());
     timer.start(1000);
}
void Enemy:: findPathToTarget(const Position *targetpos) {
    pathToPacman.clear ();
    Field = Maze::getField ();
  int height = Field.size ();
  int width  = Field[0].size();
  int tail= 0, head = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  register int iy,ix;
   if (Field[position->x][position->y] == 0 ||
      Field[targetpos->x][targetpos->y] == 0)
      return;
  Position pos;
  Position *queue = new Position[height * width];
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width;++j) {
        if (Field[i][j] != 0)
            Field[i][j] = -1;
    }
  }
  queue[tail++] = *position;
  Field[position->x][position->y]  = 1;
  while (head < tail) {
        pos = queue[head++];
        for (int k = 0; k < 4; ++k) {
            ix =  pos.x + dy[k];
            iy =  pos.y + dx[k];
             if ( ix >= 0 && ix < height && iy >= 0 &&
                iy < width && Field[ix][iy] == -1)
              {
                Field[ix][iy] = Field[pos.x][pos.y] + 1;
                queue[tail++] = Position(ix,iy);
              }
        }
        if (Field[targetpos->x][targetpos->y] != -1)
            break;
  }
    if (Field[targetpos->x][targetpos->y] == -1)
        return;
  Position seekPos(targetpos->x,targetpos->y);
  while (seekPos != *position) {
     pathToPacman.push (seekPos);
     for (int k = 0; k < 4; ++k) {
         iy=seekPos.y + dx[k],
         ix = seekPos.x + dy[k];
         if ( ix >= 0 && ix < height && iy >= 0 && iy < width &&
             (Field[ix][iy] == Field[seekPos.x][seekPos.y] - 1) && Field[ix][iy] != 0)  {
             seekPos.x  = ix;
             seekPos.y  = iy;
            break;
         }
     }
  }
}


Enemy::~Enemy () {
    delete position;
    pathToAngle.clear ();
    pathToPacman.clear();
}
