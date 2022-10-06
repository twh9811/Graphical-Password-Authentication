#include <imageDownloader.h>

QByteArray getImageFromWeb(QUrl url) {
    webManager = new QNetworkAccessManager();
    webRequest.setUrl(url);
    webReply = webManager->get(webRequest);
    return webReply->readAll();
}

