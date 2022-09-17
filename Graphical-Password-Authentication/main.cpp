#include "mainwindow.h"

#include <list>
#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QString>

QPushButton* createButton(QString filePath) {
    QPushButton *button = new QPushButton("");
    QPixmap picture(filePath);
    QIcon icon(picture);
    button->setIcon(icon);
    QSize standardSize(100,100);
    button->setIconSize(standardSize);
    return button;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::list<QString> testList;
    testList.push_front("C:\\Users\\Owner\\Desktop\\Memes\\Dame.jpg");
    QPushButton *firstTestButton = createButton(testList.front());
    firstTestButton->show();
    w.show();
    return a.exec();
}


