#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QFile>
#include <QDirIterator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MusicPlayer;
}
QT_END_NAMESPACE

class MusicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer() override;

    void initUI();
private:
    Ui::MusicPlayer *ui;
};
#endif // MUSICPLAYER_H
