#include "Maze.h"
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
QString Maze::field = "";
Maze::Maze(const Size &size)
{
 this->size.height = size.height;
 this->size.width = size.width;
}
Maze::Maze(int w, int h)
{
 this->size.height = h;
 this->size.width = w;
 QFile file(":/res/resources/maze.txt");
 if (!file.open (QIODevice::ReadOnly)) {
    QMessageBox msg;
    msg.setText ("Error! Can't read maze!");
    msg.show ();
 }
    QTextStream out(&file);
    field = out.readAll ();
}
void Maze::draw (QPainter *painter) {
    QPixmap img(":/res/resources/maze2.png");
    painter->drawPixmap (0, 0, size.width, size.height, img);
   /* painter->setBrush (Qt::red);
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
    painter->drawRect (0, 0, size.width , size.height);*/
}
void Maze::update() {

}
