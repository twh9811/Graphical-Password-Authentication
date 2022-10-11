#include "mainwindow.h"
#include <time.h>
#include "imageDownloader.h"

#include <vector>
#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QGridLayout>
#include <QtNetwork>

std::vector<QUrl> setUpFileVector() {
    std::vector<QUrl> filePathVector;
    QUrl imageUrl1("https://imgs.search.brave.com/9DB_auwysvt5y-0zp4jPu4fKGA9n37hRJ8CtwxgDErI/rs:fit:1024:768:1/g:ce/aHR0cHM6Ly8yLmJw/LmJsb2dzcG90LmNv/bS8tX29IRm0xTkFG/Nm8vVDBrQmItTjZl/MEkvQUFBQUFBQUFD/ZjgveVEwU2x5Slhn/ZlEvczE2MDAvdHJl/ZS1waWN0dXJlLS5q/cGc");
    filePathVector.push_back(imageUrl1);
    QUrl imageUrl2("https://imgs.search.brave.com/J2bImU_jS5OgjvFV6qZcJyT_rs5RZ1Zp_z--t0iTUJs/rs:fit:1200:950:1/g:ce/aHR0cHM6Ly9jYXR2/aWxscy5jb20vd3At/Y29udGVudC91cGxv/YWRzLzIwMjEvMDEv/dGFiYnktY2F0LW5h/bWVzLmpwZw");
    filePathVector.push_back(imageUrl2);
    QUrl imageUrl3("https://imgs.search.brave.com/z16JD-GYwLhLM3YcW7jANdOt1VuLahfO38sxeBrUd44/rs:fit:1200:1200:1/g:ce/aHR0cHM6Ly9kZWhh/eWY1bWh3MWg3LmNs/b3VkZnJvbnQubmV0/L3dwLWNvbnRlbnQv/dXBsb2Fkcy9zaXRl/cy8xMDc1LzIwMTkv/MDQvMjYxMTIzNTUv/ZmlyZS1oeWRyYW50/LmpwZw");
    filePathVector.push_back(imageUrl3);
    QUrl imageUrl4("https://imgs.search.brave.com/iU7B7kHMIitsqTdMrXAxGFY6_wn8i7XQ4AX4h8_HXSE/rs:fit:1200:1200:1/g:ce/aHR0cHM6Ly9zdGF0/aWMxLmhvdGNhcnNp/bWFnZXMuY29tL3dv/cmRwcmVzcy93cC1j/b250ZW50L3VwbG9h/ZHMvMjAyMC8wNC9j/YXJzLXRvLW1vZGlm/eS5qcGc");
    filePathVector.push_back(imageUrl4);


    return filePathVector;
}

std::vector<QUrl> allQURLs = setUpFileVector();

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

    for(int i=0; i<grid_area; i++){
        int randomIndex = rand() % allQURLs.size();
        QUrl picURL = allQURLs[randomIndex];
        QPushButton *button = createButton(picURL);
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


