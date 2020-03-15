#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memcache.addServers();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString value = ui->value->toPlainText();
    QString key = ui->key->toPlainText();
    qDebug()<<key<<"\n"<<value<<"\n";
    if(memcache.setCacheData(key,value)){
        qDebug()<<"data added successfuly\n";
    }else qDebug()<<"data is not added\n";

}

void MainWindow::on_pushButton_2_clicked()
{
    QString key = ui->key->toPlainText();
    QString value;
    size_t value_length;
    uint32_t flags;
    bool rc = memcache.getCacheData(key,value,value_length,flags);
    if(rc==true){
        ui->value->setText(value);
        qDebug()<<"data retrived successfully\n";
    }else qDebug()<<"unable to retrive data\n";
}
