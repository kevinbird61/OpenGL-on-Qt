#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set textBox disabled
    ui->ShowTxt->setEnabled(false);
    // Set in the String list
    QStringList shadingModel;
    shadingModel << "Flat Shading Model" << "Gourand Shading Model" << "Phong Shading Model" << "Blinn-Phong Shading Model" ;
    QStringList imageObj;
    imageObj << "image/sun.obj" << "image/earth.obj";
    QStringList imageSrc;
    imageSrc << "image/sun.bmp" << "image/earth.bmp";
    // Add into comboBox
    ui->comboBox->addItems(shadingModel);
    ui->ShowTxt->setText(ui->comboBox->currentText());
    ui->comboBox_pic_obj->addItems(imageObj);
    ui->comboBox_pic_src->addItems(imageSrc);
    // Setting QSlider
    ui->ViewSlider->setValue(90.0);
    ui->spinBox_view->setValue(90);
    ui->spinBox_LightX->setValue(15);
    ui->spinBox_LightY->setValue(15);
    ui->spinBox_LightZ->setValue(15);
    ui->ViewSliderLight_X->setValue(15.0);
    ui->ViewSliderLight_Y->setValue(15.0);
    ui->ViewSliderLight_Z->setValue(15.0);
    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),ui->ShowTxt,SLOT(setText(QString)));
    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),ui->openGLWidget,SLOT(changeShader(QString)));
    QObject::connect(ui->comboBox_pic_src,SIGNAL(currentIndexChanged(QString)),ui->openGLWidget,SLOT(changePicSrc(QString)));
    QObject::connect(ui->comboBox_pic_obj,SIGNAL(currentIndexChanged(QString)),ui->openGLWidget,SLOT(changePicObj(QString)));

    QObject::connect(ui->ViewSlider,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeViewShader(int)));
    QObject::connect(ui->ViewSliderLight_X,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeLightXPos(int)));
    QObject::connect(ui->ViewSliderLight_Y,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeLightYPos(int)));
    QObject::connect(ui->ViewSliderLight_Z,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeLightZPos(int)));

    QObject::connect(ui->ViewSlider,SIGNAL(valueChanged(int)),ui->spinBox_view,SLOT(setValue(int)));
    QObject::connect(ui->ViewSliderLight_X,SIGNAL(valueChanged(int)),ui->spinBox_LightX,SLOT(setValue(int)));
    QObject::connect(ui->ViewSliderLight_Y,SIGNAL(valueChanged(int)),ui->spinBox_LightY,SLOT(setValue(int)));
    QObject::connect(ui->ViewSliderLight_Z,SIGNAL(valueChanged(int)),ui->spinBox_LightZ,SLOT(setValue(int)));

    QObject::connect(ui->spinBox_view,SIGNAL(valueChanged(int)),ui->ViewSlider,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_LightX,SIGNAL(valueChanged(int)),ui->ViewSliderLight_X,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_LightY,SIGNAL(valueChanged(int)),ui->ViewSliderLight_Y,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_LightZ,SIGNAL(valueChanged(int)),ui->ViewSliderLight_Z,SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
