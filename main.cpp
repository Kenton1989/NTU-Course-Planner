#include "mainwindow.h"
#include "core/data_struct.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    CourseCode cz1005("CZ1005"), cz2003("CZ2003");
    qDebug() << (cz1005 > cz2003);

    return 0;//a.exec();
}
