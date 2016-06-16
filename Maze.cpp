#include "Maze.h"
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "Player.h"
#include "PowerPill.h"
#include "Game.h"
#include "Enemy.h"
QVector<QVector<int> > Maze::field;
int Maze::countPills;
Maze::Maze() : QObject(), timer(this)
{
    this->size.height = 260;
    this->size.width = 228;
    startField.resize(size.height);
    // read Map from file;
    readFieldData();
    // initialize current field and pills list
    updateData();
    // change pills list entry
    initPills ();
    // set connect on PowerPill effect
    connect(&timer,&QTimer::timeout,this, &Maze::endAngryPacmanMode);
}
void Maze::readFieldData() {
     for (int i = 0; i < size.height; ++i)
         startField[i].resize (size.width);

    QFile file(":/res/resources/maze.txt");
    if (!file.open (QIODevice::ReadOnly)) {
          QMessageBox msg;
          msg.setText ("Error! Can't read the maze!");
          msg.show ();
          return;
    }
    QString value = "";
    QTextStream out(&file);
    value = out.read (1);
    for (int i = 0; ! out.atEnd ();++i) {
        value = out.read(1);
        for (int j = 0; value != "\n" && ! out.atEnd ();++j) {
            startField[i][j] = value.toInt ();
            value = out.read (1);
        }
    }
}

void Maze::draw (QPainter *painter) {
    QPixmap img(":/res/resources/maze2.png");
    painter->drawPixmap (0, 0, size.width * 2, size.height * 2, img);
    painter->setPen (QPen(Qt::darkYellow,3,Qt::SolidLine, Qt::FlatCap));
    painter->setBrush (Qt::darkYellow);
    // draw pills
    for (auto it = pills.begin (); it != pills.end ();++it)
        it->draw (painter);
}
// init pills
void Maze::initPills() {
     for (int row  = 0; row < size.height; ++row) {
          for (int column = 0; column < size.width; ++column) {
                if (field[row][column] == 3)
                      startPills.emplace_back(PowerPill(row, column));
                else if (field[row][column] == 2)
                      startPills.emplace_back(Pill(row, column));
          }
    }
    countPills = startPills.size ();
    pills = startPills;
}
void Maze::removePill(const Position &position) {
    for (auto it = pills.begin(); it != pills.end();++it) {
            if (it->getPostion () == position) {
                pills.erase(it);
                break;
            }
    }
}

int Maze::getPillsCount () {
    return pills.size ();
}

void Maze::endAngryPacmanMode () {
    Game::setDelay (30);
}
void Maze::updateData() {
    field = startField;
    pills = startPills;
}

void Maze::update() {
    const Position * playerPosition = Player::playerPosition ();
    if (field[playerPosition->x][playerPosition->y] == 2) {
        field[playerPosition->x][playerPosition->y] = 1;
        Game::addMoney(10);
        removePill(*playerPosition);
    }
    else if (field[playerPosition->x][playerPosition->y] == 3) {
        Game::setDelay (20);
        timer.start (5000);
        field[playerPosition->x][playerPosition->y] = 1;
        Game::addMoney(20);
        removePill(*playerPosition);
    }
}
void Maze::setPillsCount () {
    countPills = startField.size ();
}

void Maze::initPlayerStartPosition () {
    int height = field.size ();
    int width = field[0].size ();
    for (int row  = 0; row < height;++row) {
         for (int column = 0; column < width;++column) {
                if (field[row][column] == 5) {
                     Player::initPosition(row, column);
                    return;
                 }
         }
    }
}
void Maze::initEnemyStartPosition () {
    int height = field.size ();
    int width = field[0].size ();
    for (int row  = 0; row < height;++row) {
        for (int column = 0; column < width; ++column) {
            if (field[row][column] == 4) {
                Enemy::initPosition(row, column);
                    return;
            }
        }
    }
}

const QVector<QVector<int> > & Maze::getField() {
    return field;
}

Maze::~Maze() {
    pills.clear ();
    startPills.clear();
}
