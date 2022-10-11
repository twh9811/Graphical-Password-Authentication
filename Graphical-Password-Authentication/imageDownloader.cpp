#include "imageDownloader.h"

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QUrl>
#include <QEventLoop>

QByteArray downloadedData;
QNetworkAccessManager* webManager;
QNetworkRequest webRequest;
QNetworkReply* webReply;


QPixmap getImageFromWeb(QUrl url) {
    webManager = new QNetworkAccessManager();
    webRequest.setUrl(url);
    webReply = webManager->get(webRequest);
    QEventLoop loop;
    QObject::connect(webReply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray bytes = webReply->readAll();
    QPixmap image;
    image.loadFromData(bytes);
    return image;
}
