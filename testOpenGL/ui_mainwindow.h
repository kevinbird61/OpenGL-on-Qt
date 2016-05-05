/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mycombobox.h"
#include "myopengl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *EditOption;
    MyComboBox *comboBox;
    QSlider *ViewSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *ViewSliderLight_X;
    QLabel *label_6;
    QSlider *ViewSliderLight_Y;
    QLabel *label_7;
    QSlider *ViewSliderLight_Z;
    QSpinBox *spinBox_view;
    QSpinBox *spinBox_LightX;
    QSpinBox *spinBox_LightY;
    QSpinBox *spinBox_LightZ;
    MyComboBox *comboBox_pic_obj;
    QLabel *label_8;
    QLabel *label_9;
    MyComboBox *comboBox_pic_src;
    MyOpenGL *openGLWidget;
    QGroupBox *groupBox;
    QTextEdit *ShowTxt;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1080, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        EditOption = new QGroupBox(centralWidget);
        EditOption->setObjectName(QStringLiteral("EditOption"));
        EditOption->setGeometry(QRect(820, 10, 251, 431));
        comboBox = new MyComboBox(EditOption);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 50, 231, 31));
        ViewSlider = new QSlider(EditOption);
        ViewSlider->setObjectName(QStringLiteral("ViewSlider"));
        ViewSlider->setGeometry(QRect(100, 110, 101, 29));
        ViewSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(EditOption);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 181, 17));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(EditOption);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 171, 17));
        label_4 = new QLabel(EditOption);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 81, 29));
        label_5 = new QLabel(EditOption);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 81, 29));
        ViewSliderLight_X = new QSlider(EditOption);
        ViewSliderLight_X->setObjectName(QStringLiteral("ViewSliderLight_X"));
        ViewSliderLight_X->setGeometry(QRect(100, 140, 101, 29));
        ViewSliderLight_X->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(EditOption);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 81, 29));
        ViewSliderLight_Y = new QSlider(EditOption);
        ViewSliderLight_Y->setObjectName(QStringLiteral("ViewSliderLight_Y"));
        ViewSliderLight_Y->setGeometry(QRect(100, 170, 101, 29));
        ViewSliderLight_Y->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(EditOption);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 200, 81, 29));
        ViewSliderLight_Z = new QSlider(EditOption);
        ViewSliderLight_Z->setObjectName(QStringLiteral("ViewSliderLight_Z"));
        ViewSliderLight_Z->setGeometry(QRect(100, 200, 101, 29));
        ViewSliderLight_Z->setOrientation(Qt::Horizontal);
        spinBox_view = new QSpinBox(EditOption);
        spinBox_view->setObjectName(QStringLiteral("spinBox_view"));
        spinBox_view->setGeometry(QRect(200, 110, 48, 27));
        spinBox_LightX = new QSpinBox(EditOption);
        spinBox_LightX->setObjectName(QStringLiteral("spinBox_LightX"));
        spinBox_LightX->setGeometry(QRect(200, 140, 48, 27));
        spinBox_LightY = new QSpinBox(EditOption);
        spinBox_LightY->setObjectName(QStringLiteral("spinBox_LightY"));
        spinBox_LightY->setGeometry(QRect(200, 170, 48, 27));
        spinBox_LightZ = new QSpinBox(EditOption);
        spinBox_LightZ->setObjectName(QStringLiteral("spinBox_LightZ"));
        spinBox_LightZ->setGeometry(QRect(200, 200, 48, 27));
        comboBox_pic_obj = new MyComboBox(EditOption);
        comboBox_pic_obj->setObjectName(QStringLiteral("comboBox_pic_obj"));
        comboBox_pic_obj->setGeometry(QRect(10, 270, 231, 31));
        label_8 = new QLabel(EditOption);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 240, 181, 17));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_9 = new QLabel(EditOption);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 310, 181, 17));
        label_9->setLayoutDirection(Qt::LeftToRight);
        comboBox_pic_src = new MyComboBox(EditOption);
        comboBox_pic_src->setObjectName(QStringLiteral("comboBox_pic_src"));
        comboBox_pic_src->setGeometry(QRect(10, 340, 231, 31));
        openGLWidget = new MyOpenGL(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(9, 9, 800, 600));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(820, 450, 251, 81));
        ShowTxt = new QTextEdit(groupBox);
        ShowTxt->setObjectName(QStringLiteral("ShowTxt"));
        ShowTxt->setGeometry(QRect(10, 40, 241, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 191, 20));
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        EditOption->setTitle(QApplication::translate("MainWindow", "User Adjustion", 0));
        label_2->setText(QApplication::translate("MainWindow", "Shading Model Selection:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Adjustment:", 0));
        label_4->setText(QApplication::translate("MainWindow", "View Scale:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Light-X:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Light-Y:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Light-Z:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Picture obj Selection:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Picture src Selection:", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Result Detail", 0));
        label->setText(QApplication::translate("MainWindow", "Current Shading Model", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
