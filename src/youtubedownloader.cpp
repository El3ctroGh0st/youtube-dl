#include "youtubedownloader.hpp"
#include "ui_youtubedownloader.h"

#include "helpdialog.hpp"

#include <QDebug>
#include <QDir>
#include <QEventLoop>
#include <QFileInfo>
#include <QMessageBox>
#include <QRegExp>
#include <QTimer>

YoutubeDownloader::YoutubeDownloader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::YoutubeDownloader)
{
    ui->setupUi(this);

    checkApplication();
    getData();

    //UI connections
    connect(ui->actionHelp, &QAction::triggered, this, &YoutubeDownloader::viewHelp);
    connect(ui->actionVersion, &QAction::triggered, this, &YoutubeDownloader::viewVersion);
}

YoutubeDownloader::~YoutubeDownloader()
{
    delete ui;
}

void YoutubeDownloader::checkApplication()
{
    //Change path on deployment
    QString appPath = QDir::currentPath() + "/debug/youtube-dl.exe";
    qDebug() << appPath;

    QFileInfo checkFile(appPath);

    if(!checkFile.exists())
    {
        QMessageBox::critical(this, "Application not found",
                              "The youtube-dl.exe could not be found.\nMake sure it is in the same directory as the executable.",
                              QMessageBox::Ok);
        QTimer::singleShot(0, this, &QMainWindow::close);
    }
}

void YoutubeDownloader::getData()
{
    QProcess *cmd = new QProcess(this);
    cmd->setWorkingDirectory(QDir::currentPath());
    cmd->start("youtube-dl", QStringList() << "--version");

    QEventLoop evLoop;
    connect(cmd, &QProcess::readyRead, &evLoop, &QEventLoop::quit);
    evLoop.exec();

    version = "Current version: " + QString(cmd->readAll());
    version.remove(QRegExp("[\\r\\n]"));
    qDebug() << version;
}

void YoutubeDownloader::viewHelp()
{
    //Add appropriate descriptions
    HelpDialog *helpDialog = new HelpDialog(this);
    helpDialog->setText(""/*String*/);

    helpDialog->show();
}

void YoutubeDownloader::viewVersion()
{
   /* QProcess *cmd = new QProcess(this);
    cmd->setWorkingDirectory(QDir::currentPath());
    cmd->start("youtube-dl", QStringList() << "--version");

    QEventLoop evLoop;
    connect(cmd, &QProcess::readyRead, &evLoop, &QEventLoop::quit);
    evLoop.exec();*/

    QMessageBox::information(this, "Version", version, QMessageBox::Ok);
}
