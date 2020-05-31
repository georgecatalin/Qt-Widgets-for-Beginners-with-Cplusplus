/* ***
 * code practice by George Calin
 * george.calin@gmail.com
 * https://ro.linkedin.com/in/cgeorge1978
 * 31.05.2020
 * *** */

#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
