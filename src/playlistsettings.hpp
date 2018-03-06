#ifndef PLAYLISTSETTINGS_HPP
#define PLAYLISTSETTINGS_HPP

#include <QWidget>

namespace Ui {
class PlaylistSettings;
}

class PlaylistSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistSettings(QWidget *parent = 0);
    ~PlaylistSettings();

private:
    Ui::PlaylistSettings *ui;
};

#endif // PLAYLISTSETTINGS_HPP
