#include "headwidget.h"

HeadWidget::HeadWidget(QWidget *parent)
    : QWidget(parent)
{
}

void HeadWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPos = event->globalPosition().toPoint() - window()->frameGeometry().topLeft();
        event->accept();        // 接受事件
    }
    // 调用父类的mousePressEvent处理事件
    QWidget::mousePressEvent(event);
}

void HeadWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) {
        window()->move(event->globalPosition().toPoint() - m_dragPos);
        event->accept();
    }
    // 调用父类的mouseMoveEvent处理事件
    QWidget::mouseMoveEvent(event);
}

void HeadWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QWidget *w = window();
        if (w->isMaximized())
            w->showNormal();
        else
            w->showMaximized();
        event->accept();
    }
    // 调用父类的mouseDoubleClickEvent处理事件
    QWidget::mouseDoubleClickEvent(event);
}