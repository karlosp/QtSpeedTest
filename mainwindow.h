#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    double current_x_ = 0;
    int current_position_ = 0;
    QTimer  graph_update_timer_;

    void update_graph();
};

#endif // MAINWINDOW_H
