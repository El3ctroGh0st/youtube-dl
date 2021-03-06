#include "videosettings.hpp"
#include "ui_videosettings.h"

#include <QComboBox>
#include <QDebug>
#include <QFileDialog>
#include <QPalette>
#include <QStandardPaths>

VideoSettings::VideoSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoSettings),
    urlEdit(new FocusTextEdit(this)),
    destinationEdit(new FocusTextEdit(this))
{
    ui->setupUi(this);

    ui->urlLayout->addWidget(urlEdit);
    destinationEdit->setReadOnly(true);
    ui->destinationLayout->addWidget(destinationEdit);

    normalFont = urlEdit->font();
    normalColor = urlEdit->palette();

    exampleFont.setItalic(true);
    exampleColor.setColor(QPalette::Text, Qt::gray);

    urlEdit->setText("https://www.youtube.com/watch?v=_S2G8jhhUHg&list=PLmKbqjSZR8TZa7wyVoVq2XMHxxWREyiFc");
    urlEdit->setFont(exampleFont);
    urlEdit->setPalette(exampleColor);

    //UI connections
    connect(urlEdit, &FocusTextEdit::focusIn, this, &VideoSettings::resetUrlEdit);
    connect(destinationEdit, &FocusTextEdit::focusIn, this, &VideoSettings::selectDestination);
    connect(ui->modelBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &VideoSettings::togglePlaylist);
}

FocusTextEdit::FocusTextEdit(QWidget *parent) :
    QLineEdit(parent)
{

}

VideoSettings::~VideoSettings()
{
    delete ui;
}

void VideoSettings::resetUrlEdit()
{
    if(defaultUrl)
    {
        urlEdit->setText("");
        urlEdit->setFont(normalFont);
        urlEdit->setPalette(normalColor);
        defaultUrl = false;
    }
}

void VideoSettings::selectDestination()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select a folder", QDir::homePath(), QFileDialog::ShowDirsOnly);

    destinationEdit->setText(dir);
}

void VideoSettings::togglePlaylist(int playlist)
{
    if(playlist == 1)
    {
        if(pSettings == nullptr)
        {
            pSettings = new PlaylistSettings(this);
            ui->playlistLayout->addWidget(pSettings);
        }

        ui->playlistLayout->itemAt(0)->widget()->setVisible(true);
    }
    else
    {
        ui->playlistLayout->itemAt(0)->widget()->setVisible(false);
    }
}

QUrl VideoSettings::getUrl() const
{
    return QUrl(urlEdit->text());
}

bool VideoSettings::getFieldsFilled() const
{
    return true;
}

void FocusTextEdit::focusInEvent(QFocusEvent *e)
{
    qDebug() << "Arrived!";
    if(e->reason() == Qt::MouseFocusReason)
        emit focusIn();
    QLineEdit::focusInEvent(e);
}

void FocusTextEdit::focusOutEvent(QFocusEvent *e)
{
    if(e->reason() == Qt::MouseFocusReason)
        emit focusOut();
    QLineEdit::focusOutEvent(e);
}
