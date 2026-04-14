#include "btform.h"
#include "ui_btform.h"
#include <QMouseEvent>
#include <QPixmap>

BtForm::BtForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BtForm)
{
    ui->setupUi(this);
}

BtForm::~BtForm()
{
    delete ui;
}

int BtForm::getPageId()
{
    return pageId;
}

// 设置自定义按钮的图片、文字以及pageID
void BtForm::section(QString btIcon, QString btText, int pageId)
{
    this->pageId = pageId;
    ui->BtIcon->setPixmap(QPixmap(btIcon));
    ui->BtText->setText(btText);
}

// 鼠标点击事件
void BtForm::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 鼠标点击后背景颜色变为绿色，文字变为白色
        ui->BtStyle->setStyleSheet(R"(
            background-color: rgb(30, 206, 154);
            color: #F6F6F6;
        )");

        emit clicked(pageId);
    }
}

// 清除按钮的样式
void BtForm::clearStyle()
{
    ui->BtStyle->setStyleSheet(R"(
        #BtStyle * {
            background-color: transparent;
            border: none;
        }
        #BtStyle:hover
        {
            background-color:#D8D8D8;
        }
    )");
}
