#include "musicplayer.h"
#include "ui_musicplayer.h"
#include <QPushButton>

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
    auto *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);                // 阴影模糊半径
    shadowEffect->setColor(QColor(0, 0, 0, 160));   // 阴影颜色
    shadowEffect->setOffset(0, 0);                  // 阴影偏移量
    this->setGraphicsEffect(shadowEffect);          // 设置窗口的图形效果
    
    connectSignalsAndSlots();

    // 点击按钮时，不传递鼠标事件给父窗口
    ui->min->setAttribute(Qt::WA_NoMousePropagation, true);
    ui->max->setAttribute(Qt::WA_NoMousePropagation, true);
    ui->quit->setAttribute(Qt::WA_NoMousePropagation, true);

    initBtForms();
}

// 连接信号槽槽函数
void MusicPlayer::connectSignalsAndSlots()
{
    // 连接min按钮的clicked信号到onMinButtonClicked槽函数
    connect(ui->min, &QPushButton::clicked, this, &MusicPlayer::onMinButtonClicked);
    connect(ui->max, &QPushButton::clicked, this, &MusicPlayer::onMaxButtonClicked);
    connect(ui->quit, &QPushButton::clicked, this, &MusicPlayer::onQuitButtonClicked);

    // 连接所有btForm按钮的clicked信号到onBtFormClicked槽函数
    QList<BtForm*> btForms = findChildren<BtForm*>();
    for (BtForm* btForm : std::as_const(btForms)) {
        connect(btForm, &BtForm::clicked, this, &MusicPlayer::onBtFormClicked);
    }
}

// 初始化btForm按钮
void MusicPlayer::initBtForms()
{
    ui->Rec->section(":/images/rec.png", "推荐", 0);
    ui->Music->section(":/images/music.png", "音乐馆", 1);
    ui->Audio->section(":/images/radio.png", "电台", 2);
    ui->Like->section(":/images/like.png", "我喜欢", 3);
    ui->Local->section(":/images/local.png", "本地下载", 4);
    ui->Recent->section(":/images/recent.png", "最近播放", 5);
}

void MusicPlayer::onMinButtonClicked()
{
    showMinimized();
}

void MusicPlayer::onMaxButtonClicked()
{
    if (isMaximized()) {
        showNormal();
    } else {
        showMaximized();
    }
}

void MusicPlayer::onQuitButtonClicked()
{
    close();
}

void MusicPlayer::onBtFormClicked(int pageId)
{
    // 1. 获取当前页面所有btForm按钮类型的对象
    QList<BtForm*> btForms = findChildren<BtForm*>();

    // 2. 遍历所有btForm按钮，将背景颜色和文字颜色重置为默认值
    for (BtForm* btForm : std::as_const(btForms)) {
        if(pageId != btForm->getPageId())
            btForm->clearStyle();
    }

    // 3. 设置当前显示页
    ui->stackedWidget->setCurrentIndex(pageId);
}
