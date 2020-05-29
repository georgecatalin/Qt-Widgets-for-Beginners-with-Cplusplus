#include "dialog.h"
#include <QApplication>

/* *** Main take away from here:
 * You can include resources in your binary file, but you can not write them in the application
 * This would required recompiling the program again
 * *** */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
