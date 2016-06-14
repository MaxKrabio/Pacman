#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Canvas.h"
class Game;
class GameLoop;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void hideMenu();
    ~MainWindow();

private slots:
    void showMenu();

    void on_ExitButton_clicked();

    void on_StartButton_clicked();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    Game *game;
    GameLoop *gloop;
};

#endif // MAINWINDOW_H
