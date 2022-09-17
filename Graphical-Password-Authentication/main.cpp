#include "mainwindow.h"
#include <time.h>

#include <vector>
#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QGridLayout>

std::vector<QString> setUpFileVector() {
    std::vector<QString> filePathVector;

    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\Dame.jpg");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\damoins_morgan.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\d o n a l d.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\Dame.jpg");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\damoins_morgan.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\d o n a l d.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\Dame.jpg");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\damoins_morgan.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\d o n a l d.png");

    return filePathVector;
}

QPushButton* createButton(QString filePath) {
    QPushButton *button = new QPushButton("");
    QPixmap picture(filePath);
    QIcon icon(picture);
    button->setIcon(icon);
    QSize standardSize(100,100);
    button->setIconSize(standardSize);
    return button;
}

void createImageGrid(QGridLayout *layout){
    std::vector<QString> filePaths = setUpFileVector();
    srand(time(NULL));
    for(int i=0; i<filePaths.size(); i++){
        int randomIndex = rand() % filePaths.size();
        QString filePath = filePaths[randomIndex];
        QPushButton *button = createButton(filePath);
        int grid_size = 3;
        int row = i % grid_size;
        int col = i / grid_size;
        layout->addWidget(button, row, col);
    }
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


