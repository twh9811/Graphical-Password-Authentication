#include "HTMLParser.h"
#include <vector>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>

std::vector<std::string> setUpTopics() {
    std::vector<std::string> topicVector;
    QString topicHTML = GetHTML("", true);

    topicVector.push_back("cat");
    topicVector.push_back("dog");
    topicVector.push_back("flower");
    topicVector.push_back("traffic light");

    topicVector.push_back("muscle car");
    topicVector.push_back("giraffe");
    topicVector.push_back("mountain range");
    topicVector.push_back("cell phone");

    topicVector.push_back("pizza");
    topicVector.push_back("hamburger");
    topicVector.push_back("hotdog");
    topicVector.push_back("cow");

    topicVector.push_back("horse");
    topicVector.push_back("bird");
    topicVector.push_back("house");
    topicVector.push_back("mouse");

    topicVector.push_back("bike");
    topicVector.push_back("computer");
    topicVector.push_back("bread");
    topicVector.push_back("corn");

    return topicVector;
}

std::string selectTopic(std::vector<std::string> topicVector) {
    srand(time(NULL));
    int randomIndex = rand() % topicVector.size();
    std::string topic = topicVector[randomIndex];
    return topic;
}

QString GetHTML(std::string topic, bool isSetup = false) {
    QEventLoop loop;
    QNetworkAccessManager *webManager = new QNetworkAccessManager();
    QNetworkRequest webRequest;
    QUrl urlRequest;
    if(isSetup){
        urlRequest = QUrl(QString::fromStdString("https://www.randomlists.com/topics?dup=false&qty=100"));
    } else {
        urlRequest = QUrl(QString::fromStdString("https://www.google.com/search?q=" + topic + "&tbm=isch"));
    }

    webRequest.setUrl(urlRequest);
    QNetworkReply *webReply = webManager->get(webRequest);

    auto status = QObject::connect(webReply,SIGNAL(finished()),&loop,SLOT(quit()));
//    qDebug() << "Connection status:" << status;
    loop.exec();

    QString html = webReply->readAll();

    return html;
}

std::vector<QString> getImageAddresses(QString html, bool isSetup = false) {
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
