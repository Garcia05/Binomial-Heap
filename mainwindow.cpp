#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bheap.cpp"
#include <QPixmap>
#include <qpixmap.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    generateMarco();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Agregar_clicked()
{

   // a.Agregar(ui->AgregarL->text().toInt());

    for(int i=1;i<=16;i++){
        a.Agregar(i);
    }
    a.generarDot();
    image.load("bheap.png");
    setimg(image);
}
void MainWindow::generateMarco(){
    ui->gridLayout_2->addWidget(&m_area, 0, 0, 1, 3);
    ui->gridLayout_2->addWidget(&m_zoomOut, 1, 0);
    ui->gridLayout_2->addWidget(&m_scaleLabel, 1, 1);
    ui->gridLayout_2->addWidget(&m_zoomIn, 1, 2);
    m_area.setWidget(&m_imageLabel);
    m_imageLabel.setScaledContents(true);
    connect(&m_zoomIn, &QPushButton::clicked, [this]{ scaleImage(1.1); });
    connect(&m_zoomOut, &QPushButton::clicked, [this]{ scaleImage(1.0/1.1); });
}
//AGREGA IMAGEN AL LABEL
void MainWindow::setimg(QPixmap & img){
    m_scaleFactor = 1.0;
    m_imageLabel.setPixmap(img);
    scaleImage(1.0);
}
void MainWindow::scaleImage(double factor){
    m_scaleFactor *= factor;
    m_scaleLabel.setText(QStringLiteral("%1%").arg(m_scaleFactor*100, 0, 'f', 1));
    QSize size = m_imageLabel.pixmap()->size() * m_scaleFactor;
    m_imageLabel.resize(size);
}

void MainWindow::on_Eliminar_clicked()
{
    a.deletemin();
    a.generarDot();
    image.load("bheap.png");
    setimg(image);
}
