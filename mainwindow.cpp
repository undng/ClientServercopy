#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVBoxLayout>
#include<QTcpSocket>
#include<QDateTime>
#include<QJsonObject>
#include<QJsonDocument>
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

    QString text = ui->textLine->text();
    QString author = ui->textLine2->text();
    QDateTime time = QDateTime::currentDateTime();
    QJsonObject tempobj;
    tempobj["message"] = text;
    tempobj["author"] =  author;
    tempobj["time"] = time.toString();
    QString sendmessage = QJsonDocument(tempobj).toJson(QJsonDocument::Compact).toStdString().c_str();
    QByteArray temp = sendmessage.toLocal8Bit();
    char* ms = temp.data();
    socket->write(ms);

}

