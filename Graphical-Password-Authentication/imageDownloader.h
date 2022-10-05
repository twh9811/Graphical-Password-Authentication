#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <QByteArray>
#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

//Variables
QByteArray downloadedData;
QNetworkAccessManager webManager;
QNetworkRequest webRequest;
QNetworkReply webReply;

//Functions
QByteArray getImageFromWeb(QString imageURL);

#endif // IMAGEDOWNLOADER_H
