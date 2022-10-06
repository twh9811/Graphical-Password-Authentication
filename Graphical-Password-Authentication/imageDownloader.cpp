#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QUrl>

QByteArray downloadedData;
QNetworkAccessManager* webManager;
QNetworkRequest webRequest;
QNetworkReply* webReply;

QByteArray getImageFromWeb(QUrl url) {
    webManager = new QNetworkAccessManager();
    webRequest.setUrl(url);
    webReply = webManager->get(webRequest);
    downloadedData = webReply->readAll();
    return downloadedData;
}


