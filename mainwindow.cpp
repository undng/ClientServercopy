#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVBoxLayout>
#include<QTcpSocket>
#include<QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //testVbox = new QVBoxLayout(ui->scrollAreaWidgetContents);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->close();
    qDebug() << socket->isOpen();
}


void MainWindow::on_sendButton_clicked()
{
    QTcpSocket* socket = new QTcpSocket(this);
    QString text = ui->textLine->text();
    QString author = ui->textLine2->text();
    QDateTime time = QDateTime::currentDateTime();
    QString sendmessage = text + author + time.toString();
    QByteArray temp = sendmessage.toLocal8Bit();
    char* ms = temp.data();
    socket->write(ms);

}

