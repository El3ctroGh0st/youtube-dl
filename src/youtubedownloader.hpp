#ifndef YOUTUBEDOWNLOADER_HPP
#define YOUTUBEDOWNLOADER_HPP

#include <QMainWindow>
#include <QProcess>
#include <QString>

namespace Ui {
class YoutubeDownloader;
}

class YoutubeDownloader : public QMainWindow
{
    Q_OBJECT

public:
    explicit YoutubeDownloader(QWidget *parent = 0);
    ~YoutubeDownloader();

public slots:
    void viewHelp();
    void viewVersion();

private:
    Ui::YoutubeDownloader *ui;

    void checkApplication();
    void getData();

    QString version;
    QString help;

    QString commandArgument;
    QProcess *cmd = nullptr;
};

#endif // YOUTUBEDOWNLOADER_HPP
