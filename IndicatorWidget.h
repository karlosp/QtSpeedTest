#ifndef INDICATORWIDGET_H
#define INDICATORWIDGET_H

#include <QWidget>

class IndicatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IndicatorWidget(QWidget *parent = 0);

signals:

public slots:
    void setIndicatorAngle(int angle);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *) override;

private:
    int angle_;
};

#endif // INDICATORWIDGET_H
