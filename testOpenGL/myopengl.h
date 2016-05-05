#ifndef MYOPENGL_H
#define MYOPENGL_H

#include "tiny_object/tiny_obj_loader.h"
#include <QGLWidget>
#include <QOpenGLShader>
#include <QTimer>
#include <QMatrix4x4>
#include <QVector>
#include <iostream>
#include <vector>
#include <string>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QMouseEvent>

using namespace std;

// Define for the objects structure
class Object_struct{
public :
    QOpenGLShaderProgram *program;
    QOpenGLVertexArrayObject *vao;
    QOpenGLBuffer *vbo_position;
    QOpenGLBuffer *vbo_texture;
    QOpenGLBuffer *vbo_normals;
    QOpenGLBuffer *vbo_indices;
    QOpenGLTexture *texture;
    QMatrix4x4 model;
};

class MyOpenGL : public QGLWidget
{
    Q_OBJECT

public:
    MyOpenGL(QWidget *parent);
    ~MyOpenGL();
    // Loading our shader
    QOpenGLShaderProgram *setup_shader(const char *vertex_shader, const char *fragment_shader);
    int add_obj(QOpenGLShaderProgram * program , const char *filename , const char *texbmp);
    void setColorAttr(QOpenGLShaderProgram *program, const QVector3D LightPos , const QVector3D camera);
    void setVS(QOpenGLShaderProgram *program, const QMatrix4x4 projection, const QMatrix4x4 view , const QMatrix4x4 model);
    void setUniformMat4(QOpenGLShaderProgram *program , const string &name, const QMatrix4x4 mat);
    void reloadShader(const char *vertex_shader , const char *fragment_shader , const char *pic_obj , const char *pic_src);
    void releaseObject();
    void render();

    void mousePressEvent(QMouseEvent *e);
public slots:
    void changeShader(QString string);
    void changeViewShader(int value);
    void changeLightXPos(int value);
    void changeLightYPos(int value);
    void changeLightZPos(int value);
    void changePicSrc(QString string);
    void changePicObj(QString string);
protected:
    void initializeGL();
    void resizeGL(int width , int height);
    void paintGL();
private:
    QList<Object_struct*> objects;
    QList<int> indicesCount;
    QOpenGLShaderProgram *program;
    QTimer *timer;
    int current_value;
    QVector3D camera;
    QVector3D lookAt;
    QVector3D lightPosition;
    QString image_obj;
    QString image_bmp;
    QString current_vs;
    QString current_fs;
    QString temp_image;
    int sun;
    // For different picture source
    int filter;
};

#endif // MYOPENGL_H
