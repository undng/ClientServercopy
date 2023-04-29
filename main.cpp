#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include "sockettest.h"
#include<QJsonObject>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SocketTest cTest;
    const QString text =  "{ \"message\": \"hello\", \"author\":\"andruha\", \"time\":\"13:77\"}";
    cTest.Connect("jsonplaceholder.typicode.com", 80);
    QJsonObject testObj = cTest.ObjectFromString(text, cTest.socket);
    //cTest.recieveMessage(testObj);
    qDebug() << testObj;

    MainWindow wa;
    //testing shit
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);
    cTest.SetLabel(&testObj, &wa);

    cTest.SetLabel(&testObj, &wa);
    wa.show();
    return a.exec();
}
