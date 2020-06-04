#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("George Calin");
    a.setOrganizationDomain("http://www.georgecalin.ro");
    a.setApplicationName("Rich Text Editor");
    a.setApplicationDisplayName("Rich Text Editor: An example");
    a.setApplicationVersion("0.1.1 Beta");

    MainWindow w;
    w.show();
    return a.exec();
}
