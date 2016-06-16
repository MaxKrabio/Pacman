#include "Enemy.h"
#include "Player.h"
#include "Maze.h"
#include <QPainter>
#include <QStack>
#include "Size.h"
Position *Enemy::position;
Enemy::Enemy() : QObject(), timer(this)
 {
    position = new Position();
     // set enemy start position
    Maze::initEnemyStartPosition ();
    connect(&timer,&QTimer::timeout,this,&Enemy::getPathToTarget);
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

void Enemy::getPathToTarget () {
  const Position * finishPos = Player::playerPosition ();
  Field = Maze::getField ();
  int height = Field.size ();
  int width  = Field[0].size();
  int tail= 0, head = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  register int iy,ix;
   if (Field[position->x][position->y] == 0 ||
      Field[finishPos->x][finishPos->y] == 0)
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
        if (Field[finishPos->x][finishPos->y] != -1)
            break;
  }
    if (Field[finishPos->x][finishPos->y] == -1)
        return;
  int x = finishPos->x;
  int y = finishPos->y;
  Position seekPos(finishPos->x,finishPos->y);
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
  timer.start(1000);
}
/*
void Enemy::getPathToTarget() {
  pathToPacman.clear ();
  const Position * playerPosition = Player::playerPosition ();
  Field = Maze::getField ();
  int height = Field.size ();
  int width  = Field[0].size();

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width;++j) {
        if (Field[i][j] != 0)
            Field[i][j] = -1;
    }
  }
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  register int x, y, d, k;
  register int iy,ix;
  bool stop;
  if (Field[position->x][position->y] == 0 ||
      Field[playerPosition->x][playerPosition->y] == 0)
      return;
  time_t t = time(0);
  int count  = 0;
  // распространение волны
  d = 6;
  Field[position->x][position->y]  = 6;
  do {
       stop = true;
     for ( y = 0; y < height; ++y )
       for ( x = 0; x < width;++x ) {
            count++;
            if ( Field[y][x] == d ) {
                for ( k = 0; k < 4; ++k ) {
                     iy=y + dy[k];
                     ix = x + dx[k];
                    if ( iy >= 0 && iy < height && ix >= 0 && ix < width &&
                         Field[iy][ix] == -1) {
                         stop = false;
                         Field[iy][ix] = d + 1;
                    }
                }
            }
       }
    ++d;
  } while ( !stop && (Field[playerPosition->x][playerPosition->y] == -1));
  if (Field[playerPosition->x][playerPosition->y] == -1)
        return;
  t = time(0) - t;
  d = Field[playerPosition->x][playerPosition->y];
  y = playerPosition->x;
  x = playerPosition->y;
  while ( d > 6 ) {
     pathToPacman.push (Position(y, x));
     d--;
     for (k = 0; k < 4; ++k) {
         int iy=y + dy[k], ix = x + dx[k];
         if ( iy >= 0 && iy < height && ix >= 0 && ix < width &&
             Field[iy][ix] == d)  {
             x = x + dx[k];
             y = y + dy[k];
            break;
         }
     }
  }
  timer.start (1000);
}
*/

/*
void Enemy::getPathToTarget () {

    bool add = true;
    pathToPacman.clear ();
    Field = Maze::getField ();
    int height = Field.size();
    int width  = Field[0].size();
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    const Position * playerPosition = Player::playerPosition ();
    int x, y, k, step = 6;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++) {
            if (Field[y][x] != 0)
                Field[y][x] = -1;//индикатор еще не ступали сюда
        }
            Field[playerPosition->x][playerPosition->y] = 6;//Начинаем с финиша
            while (add == true)
            {
                add = false;
                for (y = 0; y < width; y++)
                    for (x = 0; x <  height; x++)
                    {
                        if (Field[x][y] == step)
                        {
                            //Ставим значение шага+1 в соседние ячейки (если они проходимы)
                            if (y - 1 >= 0 && Field[x - 1][y] != 0 && Field[x - 1][y] == -1)
                                Field[x - 1][y] = step + 1;
                            if (x - 1 >= 0 && Field[x][y - 1] != 0 && Field[x][y - 1] == -1)
                                Field[x][y - 1] = step + 1;
                            if (y + 1 < width && Field[x + 1][y] != 0 &&
                                        Field[x + 1][y] == -1)
                                Field[x + 1][y] = step + 1;
                            if (x + 1 < height && Field[x][y + 1] != 0 &&
                                                         Field[x][y + 1] == -1)
                                Field[x][y + 1] = step + 1;
                        }
                     }
                step++;
                add = true;
                if (Field[position->x][position->y] != -1)//решение найдено
                    add = false;
                if (step > width * height)//решение не найдено
                    add = false;
            }
    step = Field[position->x][position->y];
    y = position->x;
    x = position->y;
    while ( step > 6 ) {
         pathToPacman.push (Position(y, x));
         step--;
         for (k = 0; k < 4; ++k) {
             int iy= y + dy[k], ix = x + dx[k];
            if ( iy >= 0 && iy < height && ix >= 0 && ix < width &&
                 Field[iy][ix] == step)  {
                    x = x + dx[k];
                    y = y + dy[k];
            break;
         }
     }
    }
    timer.start (10000);
  }
*/

Enemy::~Enemy () {
    delete position;
    pathToAngle.clear ();
    pathToPacman.clear();
}
