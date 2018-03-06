#include "playlistsettings.hpp"
#include "ui_playlistsettings.h"

PlaylistSettings::PlaylistSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistSettings)
{
    ui->setupUi(this);
}

PlaylistSettings::~PlaylistSettings()
{
    delete ui;
}
