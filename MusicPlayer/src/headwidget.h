#ifndef HEADWIDGET_H
#define HEADWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

class HeadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeadWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    QPoint m_dragPos;
};

#endif // HEADWIDGET_H