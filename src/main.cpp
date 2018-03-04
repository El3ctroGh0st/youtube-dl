#include "youtubedownloader.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    YoutubeDownloader w;
    w.show();

    return a.exec();
}
