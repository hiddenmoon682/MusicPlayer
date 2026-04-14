#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QFile>
#include <QDirIterator>
#include <QPushButton>

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
    void initBtForms();

    void connectSignalsAndSlots();
private slots:
    void onMinButtonClicked();
    void onMaxButtonClicked();
    void onQuitButtonClicked();

    void onBtFormClicked(int pageId);

private:
    Ui::MusicPlayer *ui;
};
#endif // MUSICPLAYER_H
