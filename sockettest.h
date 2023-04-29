#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QMainWindow>
#include "mainwindow.h"

class SocketTest : public QObject
{
    Q_OBJECT
public:
    explicit SocketTest(QObject *parent = 0);
    QTcpSocket* socket;
    void Connect(QString host, int port);
    ~SocketTest();
    void tcp_ready_read();
    QJsonObject ObjectFromString(const QString& in, QTcpSocket* socket);
    void SetLabel(QJsonObject* data, MainWindow* w);
signals:
    //QJsonObject recieveMessage(QJsonObject obj);

public slots:

private:


};

#endif // SOCKETTEST_H

