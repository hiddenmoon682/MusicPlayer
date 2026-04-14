#ifndef BTFORM_H
#define BTFORM_H

#include <QWidget>

namespace Ui {
class BtForm;
}

class BtForm : public QWidget
{
    Q_OBJECT

public:
    explicit BtForm(QWidget *parent = nullptr);
    ~BtForm();

    int getPageId();

    // 设置自定义按钮的图片、文字以及pageID
    void section(QString btIcon, QString btText, int pageId);

    void clearStyle();

signals:
    void clicked(int pageId);

protected:
    // 鼠标点击事件
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::BtForm *ui;
    int pageId;
};

#endif // BTFORM_H
