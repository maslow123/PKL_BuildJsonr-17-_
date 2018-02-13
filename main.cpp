#include <QCoreApplication>
#include "json.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    json json;
    return a.exec();
}
