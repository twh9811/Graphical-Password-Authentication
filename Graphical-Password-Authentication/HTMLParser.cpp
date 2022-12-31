#include "HTMLParser.h"
#include <vector>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>

std::vector<QString> setUpTopics() {
    std::vector<QString> topicVector;

    int index = 0;
    QString topicHTML = GetHTML("", true);
    qDebug() << topicHTML.toLatin1();
//    QString htmlTagStart = "<span class=\"rand_large\">";
//    QString htmlTagEnd = "</span>";
//    // if -1, not in string
//    while(index >= 0) {
//        //returns index of first character of tag, indicating there is a topic
//        index = topicHTML.indexOf(htmlTagStart, index);
//        //topic index starts right after the htmlTag
//        index = index + htmlTagStart.size();
//        int index2 = topicHTML.indexOf(htmlTagEnd, index);
//        QString topic = topicHTML.mid(index, index2-index);
//        topicVector.push_back(topic);
//    }
    return topicVector;
}

QString selectTopic(std::vector<QString> topicVector) {
    srand(time(NULL));
    int randomIndex = rand() % topicVector.size();
    QString topic = topicVector[randomIndex];
    return topic;
}

QString GetHTML(QString topic, bool isSetup = false) {
    QEventLoop loop;
    QNetworkAccessManager *webManager = new QNetworkAccessManager();
    QNetworkRequest webRequest;
    QUrl urlRequest;
    if(isSetup){
        urlRequest = QUrl(QString::fromStdString("https://randomwordgenerator.com/"));
    } else {
        std::string stdTopic = topic.toStdString();
        urlRequest = QUrl(QString::fromStdString("https://www.google.com/search?q=" + stdTopic + "&tbm=isch"));
    }

    webRequest.setUrl(urlRequest);
    QNetworkReply *webReply = webManager->get(webRequest);

    auto status = QObject::connect(webReply,SIGNAL(finished()),&loop,SLOT(quit()));
//    qDebug() << "Connection status:" << status;
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
