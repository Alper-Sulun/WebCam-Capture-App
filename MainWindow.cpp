#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), timer(new QTimer(this)) { 
    ui.setupUi(this);

    ui.btnStop->setVisible(false);

    if (ui.btnStart) {
        connect(ui.btnStart, &QPushButton::clicked, this, &MainWindow::startCapture);
    }

    if (ui.btnStop) {
        connect(ui.btnStop, &QPushButton::clicked, this, &MainWindow::stopCapture);
    }

    connect(timer, &QTimer::timeout, this, &MainWindow::updateFrame);  
}

MainWindow::~MainWindow() {
    if (cap.isOpened()) {
        cap.release();
    }
}

void MainWindow::startCapture() {
    cap.open(0);  

    if (!cap.isOpened()) {
        ui.label_cam->setText("Error: Kamera Açýlamýyor!");
        return;
    }

    timer->start(30);  

    ui.btnStart->setVisible(false);
    ui.btnStop->setVisible(true);
}

void MainWindow::stopCapture() {
    if (cap.isOpened()) {
        cap.release();
    }

    timer->stop();  

    
    ui.label_cam->clear();
    ui.label_cam->setText("Kamera Durduruldu.");

    
    ui.btnStart->setVisible(true);
    ui.btnStop->setVisible(false);
}

void MainWindow::updateFrame() {
    Mat frame;
    cap >> frame;

    if (frame.empty()) return;

    cvtColor(frame, frame, COLOR_BGR2RGB);
    QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    if (ui.label_cam) {
        ui.label_cam->setPixmap(QPixmap::fromImage(qimg).scaled(ui.label_cam->size(), Qt::KeepAspectRatio));
    }
}
