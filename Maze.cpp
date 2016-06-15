#include "Maze.h"
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
QVector<QString> Maze::field;
Maze::Maze(const Size &size)
{
 this->size.height = size.height;
 this->size.width  = size.width;
}
Maze::Maze(int w, int h)
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
        field.push_back (data);
        data = out.readLine();
    }
    initPills ();
}
void Maze::draw (QPainter *painter) {
    QPixmap img(":/res/resources/maze2.png");
    painter->drawPixmap (0, 0, size.width, size.height, img);
    painter->setPen (QPen(Qt::darkYellow,3,Qt::SolidLine, Qt::FlatCap));
    painter->setBrush (Qt::darkYellow);
            for (auto it = lstPills.begin (); it != lstPills.end ();++it)
                painter->drawEllipse (it->y * 2, it->x * 2, 3, 3);
}
void Maze::initPills() {
    int rlength = field.length ();
    int clength = field[0].length ();
    for (int row  = 0; row < rlength;++row) {
        for (int column = 0; column < clength;++column) {
            if (field[row].at (column) == '3' ||
                field[row].at (column) == '2')
                    lstPills.emplace_back(Position(row, column));
        }
    }
}

void Maze::update() {

}
