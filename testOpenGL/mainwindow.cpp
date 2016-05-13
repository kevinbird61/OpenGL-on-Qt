#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set textBox disabled
    // Set in the String list
    QStringList shadingModel;
    shadingModel << "Flat Shading Model" << "Gourand Shading Model" << "Phong Shading Model" << "Blinn-Phong Shading Model" ;
    QStringList imageObj;
    imageObj << "image/sun.obj" << "image/earth.obj";
    QStringList imageSrc;
    imageSrc << "image/sun.bmp" << "image/earth.bmp";
    // Add into comboBox
    ui->comboBox->addItems(shadingModel);
    ui->comboBox_pic_obj->addItems(imageObj);
    ui->comboBox_pic_src->addItems(imageSrc);
    // Setting QSlider
    ui->ViewSlider->setValue(90.0);
    ui->spinBox_view->setValue(90);
    ui->spinBox_LightX->setValue(15);
    ui->spinBox_LightY->setValue(15);
    ui->spinBox_LightZ->setValue(15);
    ui->spinBox_ViewPos_X->setValue(50);
    ui->spinBox_Blur_Sigma->setValue(0.1);
    ui->ViewSliderLight_X->setValue(15.0);
    ui->ViewSliderLight_Y->setValue(15.0);
    ui->ViewSliderLight_Z->setValue(15.0);
    ui->ViewPos_X->setValue(50.0);

    // Combine signal and slot for combo box and textEdit / openGL
    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),ui->openGLWidget,SLOT(changeShader(QString)));
    QObject::connect(ui->comboBox_pic_src,SIGNAL(currentIndexChanged(QString)),ui->openGLWidget,SLOT(changePicSrc(QString)));
    QObject::connect(ui->comboBox_pic_obj,SIGNAL(currentIndexChanged(QString)),ui->openGLWidget,SLOT(changePicObj(QString)));
    // Combine signal and slot for slider and openGL
    QObject::connect(ui->ViewSlider,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeViewShader(int)));
    QObject::connect(ui->ViewSliderLight_X,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeLightXPos(int)));
    QObject::connect(ui->ViewSliderLight_Y,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeLightYPos(int)));
    QObject::connect(ui->ViewSliderLight_Z,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeLightZPos(int)));
    QObject::connect(ui->ViewPos_X,SIGNAL(valueChanged(int)),ui->openGLWidget,SLOT(changeXModel(int)));
    // Combine signal and slot for Slider and spin box
    QObject::connect(ui->ViewSlider,SIGNAL(valueChanged(int)),ui->spinBox_view,SLOT(setValue(int)));
    QObject::connect(ui->ViewSliderLight_X,SIGNAL(valueChanged(int)),ui->spinBox_LightX,SLOT(setValue(int)));
    QObject::connect(ui->ViewSliderLight_Y,SIGNAL(valueChanged(int)),ui->spinBox_LightY,SLOT(setValue(int)));
    QObject::connect(ui->ViewSliderLight_Z,SIGNAL(valueChanged(int)),ui->spinBox_LightZ,SLOT(setValue(int)));
    QObject::connect(ui->ViewPos_X,SIGNAL(valueChanged(int)),ui->spinBox_ViewPos_X,SLOT(setValue(int)));
    // Combine signal and slot for spin box and Slider
    QObject::connect(ui->spinBox_view,SIGNAL(valueChanged(int)),ui->ViewSlider,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_LightX,SIGNAL(valueChanged(int)),ui->ViewSliderLight_X,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_LightY,SIGNAL(valueChanged(int)),ui->ViewSliderLight_Y,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_LightZ,SIGNAL(valueChanged(int)),ui->ViewSliderLight_Z,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_ViewPos_X,SIGNAL(valueChanged(int)),ui->ViewPos_X,SLOT(setValue(int)));
    QObject::connect(ui->spinBox_Blur_Sigma,SIGNAL(valueChanged(double)),ui->openGLWidget,SLOT(changeSigma(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
