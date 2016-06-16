#include "Enemy.h"
#include "Player.h"
#include "Maze.h"
#include <QPainter>
#include <QStack>
#include "Size.h"
Position *Enemy::position;
Enemy::Enemy()  {
    position = new Position();
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
void Enemy::getPathToTarget () {
/*    pathToPacman.clear ();
    Field = Maze::getField ();
    const Position * playerPosition = Player::playerPosition ();
    Field[playerPosition->x].replace(playerPosition->y,1,'1');
    Size  fieldSize(Size(Field[0].size (),Field.size ()));
    int len = 0;
    int deltaMove[4][2] = { {1, 0}, {0, 1},
                            {-1, 0}, {0, -1} };
    int  x ,y, k;
    int count = 0;
    QChar d = '6';
    bool stop;
    if (Field[position->x].at (position->y) == '0' ||
        Field[playerPosition->x].at (playerPosition->y) == '0' ) {
            return;
    }
    //start position marker as 6
    Field[position->x].replace(position->y,1,'6');
    do {
            stop = true;
            for (y = 0; y < fieldSize.height; ++y) {
                for (x = 0; x < fieldSize.width; ++x) {
                // 54 -> start pos = 6 + 48->'6'
                 if (Field[y].at (x) == d)  {
                     for (int k = 0; k < 4; ++k) {
                        int iy =  y + deltaMove[k][1];
                        int ix = x + deltaMove[k][0];
                        if (ix >= 0 && ix < fieldSize.width  &&
                            iy >= 0 &&   iy < fieldSize.height &&
                             Field[iy].at(ix) != '0') {
                                stop = false;
                                Field[iy].replace (ix, 1,d.unicode ()+ 1);
                             }
                     }
                 }

                }
            }
            d = d.unicode () + 1;
            ++count;
         } while (!stop && (Field[playerPosition->x].at (playerPosition->y) == '1'||
             Field[playerPosition->x].at (playerPosition->y) == '2' ||
             Field[playerPosition->x].at (playerPosition->y) == '3'));
          // if (grid[by][bx] == BLANK) return false;  // путь не найден
            if (Field[playerPosition->x].at (playerPosition->y) == '0')
                    return; // the wasn't found
            //start  the way restoring
        d = Field[playerPosition->x].at(playerPosition->y);
        // восстановление пути
      //  len = grid[by][bx];            // длина кратчайшего пути из (ax, ay) в (bx, by)
        x = playerPosition->y;
        y = playerPosition->x;
       // d = len + '0';
      while ( d > '6' ) {
                pathToPacman.push (Position(x,y));
                d = d.unicode() - 1;
                for (k = 0; k < 4; ++k) {
                    int iy=y + deltaMove[k][1];
                    int ix = x + deltaMove[k][0];
                    if (ix >= 0 && ix < fieldSize.width  &&
                        iy >= 0 &&   iy < fieldSize.height &&
                        Field[iy].at(ix) == d ) {

                                x = x + deltaMove[k][0];
                                y = y + deltaMove[k][1];
                        // переходим в ячейку, которая на 1 ближе к старту
                        break;
                    }
                }
        }
        */

}
void Enemy::update () {
    getPathToTarget ();
    move();
}
void Enemy::move() {
    //*position = pathToPacman.top ();
    //pathToPacman.removeFirst ();

}
Enemy::~Enemy () {
    delete position;
    pathToAngle.clear ();
    pathToPacman.clear();
}
