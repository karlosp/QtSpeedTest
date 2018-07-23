#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_graph->xAxis->setVisible(false);
    ui->widget_graph->yAxis->setVisible(false);
    ui->widget_graph->setBackground(Qt::transparent);
    ui->widget_graph->addGraph();
    ui->widget_graph->graph()->setPen(QPen(QColor("#5FE555"), 2));
    ui->widget_graph->xAxis->setRange(0,200);

    graph_update_timer_.setInterval(100);
    connect(&graph_update_timer_, &QTimer::timeout, [this](){
        update_graph();
    });
    graph_update_timer_.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
#include <qmath.h>
double angle_to_speed(int angle){
    return 325.01 + (0.2925318 - 325.5734)/(1 + qPow(angle/362.6329, 4.036375));
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    current_position_ = position;
    ui->label_speed->setText(QString::number(angle_to_speed(position), 'f',2));
    ui->widget_indicator->setIndicatorAngle(current_position_);
}

void MainWindow::update_graph()
{

    ui->widget_graph->graph()->addData(current_x_++, current_position_);
    ui->widget_graph->yAxis->rescale();
    if(current_x_ > 200){
        ui->widget_graph->xAxis->setRange(current_x_-200,current_x_);
    }
    ui->widget_graph->replot();
}
