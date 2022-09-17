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
#include <QHash>
#include <QHashIterator>

std::vector<QString> setUpFileVector() {
    std::vector<QString> filePathVector;

    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\Dame.jpg");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\damoins_morgan.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\d o n a l d.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\damon.png");
    filePathVector.push_back("C:\\Users\\Owner\\Desktop\\Memes\\drippy.png");

    return filePathVector;
}

std::vector<QString> filePaths = setUpFileVector();

QPushButton* createButton(QString filePath) {
    QPushButton *button = new QPushButton("");
    QPixmap picture(filePath);
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

    for(int i=0; i<grid_area; i++){
        int randomIndex = rand() % filePaths.size();
        QString filePath = filePaths[randomIndex];
        QPushButton *button = createButton(filePath);
        int row = i % grid_size;
        int col = i / grid_size;
        layout->addWidget(button, row, col);
    }

    QPushButton *button = new QPushButton("Submit");
    layout->addWidget(button, grid_size+1, grid_size-1);
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


