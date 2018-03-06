#ifndef VIDEOSETTINGS_HPP
#define VIDEOSETTINGS_HPP

#include <QWidget>
#include <QFocusEvent>
#include <QFont>
#include <QPalette>
#include <QLineEdit>
#include <QUrl>

#include "playlistsettings.hpp"

namespace Ui {
class VideoSettings;
}

class FocusTextEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit FocusTextEdit(QWidget *parent = nullptr);

signals:
    void focusIn();
    void focusOut();

protected:
    void focusOutEvent(QFocusEvent *);
    void focusInEvent(QFocusEvent *);
};

class VideoSettings : public QWidget
{
    Q_OBJECT

public:
    explicit VideoSettings(QWidget *parent = 0);
    ~VideoSettings();

    QUrl getUrl() const;
    bool getFieldsFilled() const;

public slots:
    void resetUrlEdit();
    void togglePlaylist(int);
    void selectDestination();

signals:
    void inputChanged();

private:
    Ui::VideoSettings *ui;

    QUrl videoUrl;

    QFont exampleFont;
    QFont normalFont;
    QPalette exampleColor;
    QPalette normalColor;

    //UI
    FocusTextEdit *urlEdit = nullptr;
    FocusTextEdit *destinationEdit = nullptr;

    bool defaultUrl = true;

    PlaylistSettings *pSettings = nullptr;
};

#endif // VIDEOSETTINGS_HPP
