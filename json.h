#ifndef JSON_H
#define JSON_H


#include <QStringList>
#include <QDir>
#include <QDebug>
#include <QJsonArray>

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QProcess>
#include <QObject>

#define PATH_JSON                    "array.json"
#define PATH_BIN                     "array.dat"
#define PATH_STATUS                  "../Service/cek_status_monita_service.sh"

class json
{
public:
    json();
    QProcess *process = new QProcess();
    QString cekStatus;
    QString result;
    QStringList list_result;
};



#endif
