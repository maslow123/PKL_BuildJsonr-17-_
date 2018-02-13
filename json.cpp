#include "json.h"

json::json(){
    cekStatus  = PATH_STATUS;
    process ->start(cekStatus);
    process ->waitForFinished();
    result = process ->readAllStandardOutput();
    list_result = result.split("\n");

    QJsonObject service;
        service["Name"]   = "Monita_Service";
        service["Status"] =  list_result.at(0);
    QJsonArray list_service;
        list_service.append(service);
        service["Name"]   = "Monita_Service2";
        service["Status"] =  list_result.at(0);
        list_service.append(service);
    QJsonObject conf;
         conf["Monita"] = list_service;
    QJsonDocument jsonDoc(conf);

    QFile fileJson(PATH_JSON);
    QFile fileBin (PATH_BIN);
        if(!fileJson.exists() && !fileBin.exists()){
             qDebug()<< "Data is successfull to create.."<<endl;
             Q_ASSERT(fileJson.open(QFile::WriteOnly));
             Q_ASSERT(fileBin.open(QFile::WriteOnly));
             fileJson.write(jsonDoc.toJson());
             fileBin.write (jsonDoc.toBinaryData());
             fileJson.close();
             fileBin.close();
             if(fileJson.exists() && fileBin.exists()){
                  qDebug()<<"The result of data is..."<<endl;
                  Q_ASSERT(fileJson.open(QFile::ReadOnly));
                  Q_ASSERT(fileBin. open(QFile::ReadOnly));

                  QJsonDocument docJson =  QJsonDocument::fromJson(fileJson.readAll());
                  QJsonDocument docBin  =  QJsonDocument::fromBinaryData(fileBin.readAll());
//        reading the data that was made
                  qDebug()<<"Result 1 : "<<docJson<<endl;
                  qDebug()<<"Result 2 : "<<docBin<<endl;
            }else{qDebug()<<"Something wrong in project ..";}
        }else{
             qDebug()<<"Reading the data ...  "<<endl;
             Q_ASSERT(fileJson.open(QFile::ReadOnly));
             Q_ASSERT(fileBin. open(QFile::ReadOnly));
             QJsonDocument docJson = QJsonDocument::fromJson(fileJson.readAll());
             QJsonDocument docBin  = QJsonDocument::fromBinaryData(fileBin.readAll());
             qDebug()<<"Result 1 : "<<docJson<<endl;
             qDebug()<<"Result 2 : "<<docBin<<endl;
        }

}

