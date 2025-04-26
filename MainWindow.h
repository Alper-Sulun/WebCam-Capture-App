#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPixmap>
#include <QTimer>

using namespace std;
using namespace cv;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void startCapture();  
    void stopCapture();
    void updateFrame();   

private:
    Ui::MainWindowClass ui;
    VideoCapture cap;
    QTimer* timer;
};
