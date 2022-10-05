#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>

//Variables
QByteArray downloadedData;
QNetworkAccessManager* webManager;
QNetworkRequest webRequest;
QNetworkReply* webReply;

//Functions
QByteArray getImageFromWeb(QString imageURL);
QPixmap turnBytesIntoPixmap(QByteArray imageBytes);

#endif // IMAGEDOWNLOADER_H
