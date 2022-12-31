#include "HTMLParser.h"
#include <vector>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>

std::vector<QString> setUpTopics() {
    std::vector<QString> topicVector;
    QString topic;
    int index = 0;
    QString topicHTML = GetHTML("", true);
//    qDebug() << topicHTML.toLatin1();
    QStringList individualTopics = topicHTML.split(",");
    for(int i =0; i<individualTopics.size(); i++) {
        topic = individualTopics[i];
        if(topic.size() != 0) {
            topicVector.push_back(topic);
//            qDebug() << topic.toLatin1();
        }
    }
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
        urlRequest = QUrl(QString::fromStdString("https://www.wordgenerator.net/application/p.php?id=charades_easy&type=1&spaceflag=false"));
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
