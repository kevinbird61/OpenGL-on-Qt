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
#include <QOpenGLFramebufferObject>
#include <QtMath>

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
    void normalizeAndset(int x , int y);

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
public slots:
    void changeShader(QString string);
    void changeViewShader(int value);
    void changeLightXPos(int value);
    void changeLightYPos(int value);
    void changeLightZPos(int value);
    void changePicSrc(QString string);
    void changePicObj(QString string);
    void changeXModel(int value);
    void changeSigma(double sigma);
protected:
    void initializeGL();
    void resizeGL(int width , int height);
    void paintGL();
private:
    // Contain the objects , index in the shader program
    QList<Object_struct*> objects;
    QList<int> indicesCount;
    // Currently program and render to texture program
    QOpenGLShaderProgram *program;
    QOpenGLShaderProgram *RTX_program;

    QOpenGLBuffer *vbo;
    QOpenGLVertexArrayObject *vao;
    // Updating the frame's timer
    QTimer *timer;
    // Replace the origin - glfwGetTime()
    int current_value;
    // For glm::vec3 , view point , view and light position in vertex shader
    QVector3D camera;
    QVector3D lookAt;
    QVector3D lightPosition;
    // Keep the image for obj file and bmp file
    QString image_obj;
    QString image_bmp;
    // Keep the current vertex shader and fragment shader
    QString current_vs;
    QString current_fs;
    QString temp_image;
    int sun;
    // For different picture source
    int filter;
    // For rotate speed control
    float rotate_speed;
    // QGLFrameBufferObject
    QOpenGLFramebufferObject *framebuffer;
    // For Gaussian Blur sigma
    QMatrix3x3 Gaussian;
};

#endif // MYOPENGL_H
