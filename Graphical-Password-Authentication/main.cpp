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
    return button;
}

std::vector<QPushButton*> createAllButtons() {
    std::vector<QPushButton*> buttonVector;
    for(int i=0; i<filePaths.size(); i++) {
        QString filePath = filePaths[i];
        QPushButton *button = createButton(filePath);
        buttonVector.push_back(button);
    }
    return buttonVector;
}

void createImageGrid(QGridLayout *layout){
    srand(time(NULL));
    int grid_size = 3;
    int grid_area = grid_size * grid_size;
    std::vector<QPushButton*> allButtons = createAllButtons();
    for(int i=0; i<grid_area; i++){
        int randomIndex = rand() % allButtons.size();
        QPushButton* button = allButtons[randomIndex];
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


