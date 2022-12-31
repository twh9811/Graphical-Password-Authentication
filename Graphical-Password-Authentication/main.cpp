#include "mainwindow.h"
#include <time.h>
#include "imageDownloader.h"
#include "HTMLParser.h"

#include <vector>
#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QGridLayout>
#include <QtNetwork>
#include <QLabel>

QPushButton* createButton(QUrl imageURL) {
    QPushButton *button = new QPushButton("");
    QPixmap picture = getImageFromWeb(imageURL);
    QIcon icon(picture);
    button->setIcon(icon);
    QSize standardSize(100,100);
    button->setIconSize(standardSize);
    button->setCheckable(true);
    return button;
}

void createImageGrid(QGridLayout *layout){
    srand(time(NULL));
    int grid_size = 3;
    int grid_area = grid_size * grid_size;

    std::vector<QString> topics = setUpTopics();
    std::vector<QString> pickedTopics;
    for(int i=0; i<grid_area; i++){
        QString topic = selectTopic(topics);
        topics.pop_back();
        pickedTopics.push_back(topic);
        QString html = GetHTML(topic, false);
//        qDebug() << html.toLatin1();
        //gets multiple image urls per 1 topic that can be randomly selected
        std::vector<QString> imageAddresses = getImageAddresses(html);
        int randomIndex = rand() % imageAddresses.size();
        QString picURL = imageAddresses[randomIndex];
//        qDebug(picURL.toLatin1());
        QPushButton *button = createButton(picURL);
        int row = i % grid_size;
        int col = i / grid_size;
        layout->addWidget(button, row, col);
    }

    QPushButton *button = new QPushButton("Submit");
    layout->addWidget(button, grid_size+1, grid_size-1);

    QLabel *statementLabel = new QLabel("Please select all pictures of: ");
    layout->addWidget(statementLabel,grid_size+1,0);

    QString pickedTopic = selectTopic(pickedTopics);
    QLabel *topicLabel = new QLabel();
    topicLabel->setText(pickedTopic);
    layout->addWidget(topicLabel,grid_size+1,1);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QWidget *window = new QWidget();
    QGridLayout *layout = new QGridLayout();
    createImageGrid(layout);

    window->setLayout(layout);
    window->show();
    return a.exec();
}


