#include "sockettest.h"
#include<QJsonObject>
#include<QJsonDocument>
#include <QMainWindow>
#include<QLabel>
#include "ui_mainwindow.h"
SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    const QString text =  "{ \"message\": \"hello\", \"author\":\"andruha\", \"time\":\"13:77\"}";
}

void SocketTest::Connect(QString host, int port)
{
    const QString text =  "{ \"message\": \"hello\", \"author\":\"andruha\", \"time\":\"13:77\"}";
    socket->connectToHost(host, port);


        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connected!";

            // send
            socket->write("hello server");
            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);
            qDebug() << "Reading: " << socket->bytesAvailable();

            qDebug() << socket->readAll();

            socket->close();
        }
        else
        {
            qDebug() << "Not connected!";
        }

}

QJsonObject SocketTest::ObjectFromString(const QString& in, QTcpSocket* socket)
{
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    // check validity of the document
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object" << Qt::endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << in << Qt::endl;
    }

    return obj;
}

void SocketTest::SetLabel(QJsonObject *data, MainWindow *w){

    QString strdata = (*data)["message"].toString();
    QLabel* newlabel = new QLabel(strdata, w);
    //newlabel->setText(strdata)
    newlabel->setStyleSheet("color: #61dafb;");
    w->ui->verticalLayout->addWidget(newlabel);

}
SocketTest::~SocketTest(){

}

