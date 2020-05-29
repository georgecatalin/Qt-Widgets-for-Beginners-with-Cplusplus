#ifndef MYLIB_H
#define MYLIB_H


#include <QString>
#include <QFile>
#include <QTextStream>

#include "MyLib_global.h"


class MYLIB_EXPORT MyLib
{
public:
    MyLib();

    QString message();
    QString test();
};

#endif // MYLIB_H
