#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <iostream>
#include <QComboBox>
#include <QGroupBox>
#include <QTextEdit>
#include "myopengl.h"

class MyComboBox : public QComboBox
{
    Q_OBJECT
public:
    MyComboBox(QGroupBox *parent);
};

#endif // MYCOMBOBOX_H
