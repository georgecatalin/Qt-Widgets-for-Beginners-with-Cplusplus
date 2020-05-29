#include "mylib.h"

MyLib::MyLib()
{

    //Force loading of the resources
    Q_INIT_RESOURCE(resources);

}

QString MyLib::message()
{
    QString msg;

    QFile file(":/files/data/readme.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        msg = stream.readAll();
        file.close();
    }

    return  msg;
}

QString MyLib::test()
{
    QString msg = "this is a test!";
    return msg;
}
