#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QUrl>

//Variables
QByteArray downloadedData;
QNetworkAccessManager* webManager;
QNetworkRequest webRequest;
QNetworkReply* webReply;
QUrl imageURL;
QPixmap finalImage;

//Functions
QByteArray getImageBytesFromWeb(QUrl imageURL);

#endif // IMAGEDOWNLOADER_H
