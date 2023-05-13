#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include "sockettest.h"
#include<QJsonObject>
#include<unistd.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SocketTest cTest;




    //cTest.recieveMessage(testObj);
    //qDebug() << testObj;

    MainWindow wa;
    //testing shit
    wa.socket = cTest.Connect("localhost", 8000, &wa);

    //QString text =  "{ \"message\": \"hellouuu\", \"author\":\"andruha\", \"time\":\"13:77\"}";
    //sleep(1);

    //QJsonObject testObj = cTest.ObjectFromString(text, cTest.socket);
    //cTest.SetLabel(&testObj, &wa);

    //text =  "{ \"message\": \"byebye\", \"author\":\"andruha\", \"time\":\"13:77\"}";
    //testObj = cTest.ObjectFromString(text, cTest.socket);
    //cTest.SetLabel(&testObj, &wa);

    wa.show();
    return a.exec();
}
