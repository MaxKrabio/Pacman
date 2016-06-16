#include "Maze.h"
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "Player.h"
#include "PowerPill.h"
#include "Game.h"
#include "Enemy.h"
QVector<QString> Maze::field;
int Maze::countPills;
/*Maze::Maze(const Size &size) : QObject()
{
 this->size.height = size.height;
 this->size.width  = size.width;

}*/
Maze::Maze(int w, int h) : QObject(), timer(this)
{
 this->size.height = h;
 this->size.width = w;
 QFile file(":/res/resources/maze.txt");
 if (!file.open (QIODevice::ReadOnly)) {
    QMessageBox msg;
    msg.setText ("Error! Can't read the maze!");
    msg.show ();
 }
    QTextStream out(&file);
    QString data = out.readLine ();
    while (data != "") {
        startField.push_back (data);
        data = out.readLine();
    }
    updateData();
    initPills ();
    initPlayerStartPosition();
    initEnemyStartPosition ();
    connect(&timer,&QTimer::timeout,this, &Maze::endAngryPacmanMode);
}
void Maze::draw (QPainter *painter) {
    QPixmap img(":/res/resources/maze2.png");
    painter->drawPixmap (0, 0, size.width, size.height, img);
    painter->setPen (QPen(Qt::darkYellow,3,Qt::SolidLine, Qt::FlatCap));
    painter->setBrush (Qt::darkYellow);
            for (auto it = pills.begin (); it != pills.end ();++it)
                it->draw (painter);
}
void Maze::initPills() {
    int rlength = field.length ();
    int clength = field[0].length ();
    for (int row  = 0; row < rlength;++row) {
        for (int column = 0; column < clength;++column) {
            if (field[row].at (column) == '3')
                    startPills.emplace_back(PowerPill(row, column));
            else if (field[row].at (column) == '2')
                    startPills.emplace_back(Pill(row, column));
        }
    }
    countPills = startPills.size ();
    pills = startPills;
}
void Maze::removePill(const Position &position) {
    for (auto it = pills.begin(); it != pills.end(); ++it) {
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
    if (field[playerPosition->x].at(playerPosition->y) == '2') {
        field[playerPosition->x].replace (playerPosition->y, 1, "1");
        Game::addMoney(10);
        removePill(*playerPosition);
    }
    else if (field[playerPosition->x].at(playerPosition->y) == '3') {
        Game::setDelay (20);
        timer.start (5000);
        field[playerPosition->x].replace (playerPosition->y, 1, "1");
        Game::addMoney(20);
        removePill(*playerPosition);
    }
}
void Maze::setPillsCount () {
    countPills = startField.size ();
}

void Maze::initPlayerStartPosition () {
    int rlength = field.length ();
    int clength = field[0].length ();
    for (int row  = 0; row < rlength;++row) {
         for (int column = 0; column < clength;++column) {
                if (field[row].at(column) == '5') {
                     Player::initPosition(row, column);
                    return;
                 }
         }
    }
}
void Maze::initEnemyStartPosition () {
    int rlength = field.length ();
    int clength = field[0].length ();
    for (int row  = 0; row < rlength;++row) {
         for (int column = 0; column < clength;++column) {
                if (field[row].at(column) == '4') {
                     Enemy::initPosition(row, column);
                    return;
                 }
         }
    }
}

QVector<QString> Maze::getField () {
    return field;
}

Maze::~Maze() {
    pills.clear ();
    startPills.clear();
}
