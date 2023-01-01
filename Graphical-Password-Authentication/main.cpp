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
#include <QHash>

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

QHash<QString, std::vector<QPushButton*>> createImageGrid(QGridLayout *layout){
    srand(time(NULL));
    int grid_size = 3;
    int grid_area = grid_size * grid_size;

    std::vector<QString> topics = setUpTopics();
    std::vector<QString> pickedTopics;

   QHash<QString, std::vector<QPushButton*>> pickedTopicsAndButtons;

    for(int i=0; i<grid_area;){
        QString topic = selectTopic(topics);
        pickedTopics.push_back(topic);
        QString html = GetHTML(topic, false);
//        qDebug() << html.toLatin1();
        //gets multiple image urls per 1 topic that can be randomly selected
        std::vector<QString> imageAddresses = getImageAddresses(html);
        //Bugged right now, if it goes any higher another button is added for some reason, 3 is highest it can be.
        int max_topic_repeats = 3;
        for(int j=0; j< rand() % max_topic_repeats; j++) {
            int randomIndex = rand() % imageAddresses.size();
            QString picURL = imageAddresses[randomIndex];
    //        qDebug(picURL.toLatin1());
            QPushButton *button = createButton(picURL);
            if(pickedTopicsAndButtons[topic].size() != 0) {
                std::vector<QPushButton*> currButtonList = pickedTopicsAndButtons[topic];
                currButtonList.push_back(button);
                pickedTopicsAndButtons[topic] = currButtonList;
            } else {
                std::vector<QPushButton*> newButtonList;
                newButtonList.push_back(button);
                pickedTopicsAndButtons[topic] = newButtonList;
            }
            int row = i % grid_size;
            int col = i / grid_size;
            layout->addWidget(button, row, col);
            i++;
        }

//        QHashIterator<QString, std::vector<QPushButton*>> iterator(pickedTopicsAndButtons);
//        while(iterator.hasNext()) {
//            iterator.next();
//            qDebug() << iterator.key() << iterator.value();
//        }

        return pickedTopicsAndButtons;
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


