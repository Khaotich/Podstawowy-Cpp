#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()) );
    //connect(ui->przycisk, SIGNAL(clicked()), ui->widget, SLOT(toggle_animation()));

    //ustawiam szare tło
    this->setStyleSheet("background-color: lightGrey");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koniec_programu()
{
    //zadanie 2
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Zamykanie programu", "Czy napewno chcesz zamknąć program?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        qApp->quit();
    }
}

void MainWindow::on_action_O_programie_triggered()
{
    QMessageBox::aboutQt(this,"O wspaniałym programie");
}

//zadanie 4
void MainWindow::on_przycisk_clicked()
{
    if(ui->przycisk->text() == "Stop") ui->przycisk->setText("Start");
    else ui->przycisk->setText("Stop");
}
