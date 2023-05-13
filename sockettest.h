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
    QTcpSocket* Connect(QString host, int port, MainWindow* w);
    ~SocketTest();
    void tcp_ready_read();
    QJsonObject ObjectFromString(const QString& in, QTcpSocket* socket);
    void SetLabel(QJsonObject* data, MainWindow* w);
    MainWindow* wa;

signals:
    //QJsonObject recieveMessage(QJsonObject obj);

public slots:
    void work();

private:


};

#endif // SOCKETTEST_H

