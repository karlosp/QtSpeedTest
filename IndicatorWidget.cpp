#include "IndicatorWidget.h"

#include <QPainter>
#include <QDebug>

IndicatorWidget::IndicatorWidget(QWidget *parent) : QWidget(parent)
{
angle_ = 0;
}

void IndicatorWidget::setIndicatorAngle(int angle)
{
    angle_ = angle;
    qDebug() << angle_;
    update();
}



void IndicatorWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    auto center = QPoint(size().width()/2, size().height()/2);
    //painter.drawEllipse(center, size().width()/2, size().height()/2);
    static const QPointF points[4] = {
        QPointF(-5, 0),
        QPointF(5, 0),
        QPointF(1, center.ry()*0.9),
        QPointF(-1, center.ry()*0.9)

    };

    static const auto white = QColor(Qt::white);
    painter.setPen(white);
    painter.setBrush(QBrush(white));

    painter.translate(center);
    painter.rotate(angle_);
    painter.drawConvexPolygon(points, 4);


//    painter.drawLine(0,0,size().width(), size().height());

//    painter.drawLine(0,size().height(),size().width(), 0);

}
