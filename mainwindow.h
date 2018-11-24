#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "bheap.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void generateMarco();
        void setimg(QPixmap & img);
        void scaleImage(double factor);

private slots:
    void on_Agregar_clicked();

    void on_Eliminar_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    Bheap<int> a;

    QScrollArea m_area;
        QLabel m_imageLabel, m_scaleLabel;
        QPushButton m_zoomOut{"-"}, m_zoomIn{"+"};
        double m_scaleFactor = 1.0;
};

#endif // MAINWINDOW_H
