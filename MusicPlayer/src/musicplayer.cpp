#include "musicplayer.h"
#include "ui_musicplayer.h"

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    initUI();

}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

void MusicPlayer::initUI()
{
    setWindowFlag(Qt::WindowType::FramelessWindowHint);

    // 给窗口的边框设置阴影
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);                // 阴影模糊半径
    shadowEffect->setColor(QColor(0, 0, 0, 160));   // 阴影颜色
    shadowEffect->setOffset(0, 0);                  // 阴影偏移量
    this->setGraphicsEffect(shadowEffect);          // 设置窗口的图形效果

}
