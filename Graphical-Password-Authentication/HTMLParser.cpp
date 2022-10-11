#include "HTMLParser.h"
#include <vector>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>

std::vector<std::string> setUpTopics() {
    std::vector<std::string> topicVector;
    topicVector.push_back("cat");
    topicVector.push_back("dog");
    topicVector.push_back("flower");
    topicVector.push_back("traffic light");

    return topicVector;
}

std::string selectTopic(std::vector<std::string> topicVector) {
    srand(time(NULL));
    int randomIndex = rand() % topicVector.size();
    std::string topic = topicVector[randomIndex];
    return topic;
}

QString GetHTML(std::string topic) {
    QEventLoop loop;
    QNetworkAccessManager *webManager = new QNetworkAccessManager();
    QNetworkRequest webRequest;
    QUrl urlRequest = QUrl(QString::fromStdString("https://www.google.com/search?q=" + topic + "&tbm=isch"));
    webRequest.setUrl(urlRequest);

    QNetworkReply *webReply = webManager->get(webRequest);


    auto status = QObject::connect(webReply,SIGNAL(finished()),&loop,SLOT(quit()));
    qDebug() << "Connection status:" << status;
    loop.exec();

    QString html = webReply->readAll();

    return html;
}

std::vector<QString> getImageAddresses(QString html) {
    std::vector<QString> imageAddresses;
    int index = 0;
    while(index >= 0) {
        index = html.indexOf("src=\"https", index);
        index = index + 5;
        int index2 = html.indexOf("\"", index);
        QString parsedImageURL = html.mid(index, index2-index);
        imageAddresses.push_back(parsedImageURL);
        index = html.indexOf("<img", index);
    }
    return imageAddresses;
}
