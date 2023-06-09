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
    connect(socket, &QTcpSocket::readyRead, this, &SocketTest::work);

}
void SocketTest::work(){

        QByteArray bytesmes = socket->readAll();
        qDebug() << "readed";
        QJsonObject obj = this->ObjectFromString(QString(bytesmes), socket);
        this->SetLabel(&obj, wa);


}
QTcpSocket* SocketTest::Connect(QString host, int port, MainWindow* w)
{
    const QString text =  "{ \"message\": \"hello\", \"author\":\"andruha\", \"time\":\"13:77\"}";
    socket->connectToHost(host, port);

    wa = w;
        if(socket->waitForConnected(3000))
        {
            qDebug() << "Connected!";

            // send
            //socket->write("hello server");
            //socket->waitForBytesWritten(1000);
            //socket->waitForReadyRead(3000);
            //qDebug() << "Reading: " << socket->bytesAvailable();

            //qDebug() << socket->readAll();


        }
        else
        {
            qDebug() << "Not connected!";
        }
        return socket;
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

    QString message = (*data)["message"].toString();
    QString author = (*data)["author"].toString();
    QString time = (*data)["time"].toString();
    QLabel* newlabel = new QLabel(message + " " + author + " " + time, w);
    //newlabel->setText(strdata)
    newlabel->setStyleSheet("color: #61dafb;");
    w->ui->verticalLayout->addWidget(newlabel);

}
SocketTest::~SocketTest(){

}

