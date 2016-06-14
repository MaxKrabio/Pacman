#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Size.h"
#include "Game.h"
#include "GameLoop.h"
#include <QDesktopWidget>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setMinimumSize (QApplication::desktop ()->width ()  / 2, QApplication::desktop ()->height () / 2);
    this->game = new Game(this->width (), this->height ());
    this->canvas = new Canvas(game,this);
    this->gloop = new GameLoop(game, canvas);
    this->gloop->setParent (this);
    canvas->setGeometry (0 , 0, this->width (), this->height ());
    canvas->setMaximumSize (this->width (), this->height ());
    canvas->setVisible (false);
   // this->layout ()->addWidget (canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideMenu() {
    ui->StartButton->setVisible (false);
    ui->SettingsButton->setVisible(false);
    ui->ScoreButton->setVisible(false);
    ui->ExitButton->setVisible (false);
}
void MainWindow::showMenu() {
    ui->StartButton->setVisible (true);
    ui->SettingsButton->setVisible(true);
    ui->ScoreButton->setVisible(true);
    ui->ExitButton->setVisible (true);
    this->canvas->setVisible (false);
}

void MainWindow::on_ExitButton_clicked()
{
    exit(EXIT_SUCCESS);
}
void MainWindow::on_StartButton_clicked()
{
    hideMenu();
    canvas->show ();
    gloop->start ();
    connect(gloop, SIGNAL(finished()), this, SLOT(showMenu()));
}
