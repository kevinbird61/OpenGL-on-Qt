#include "myopengl.h"

MyOpenGL::MyOpenGL(QWidget *parent) : QGLWidget(parent)
{
    QGLFormat format;
    format.setVersion(3,3);
    format.setProfile(QGLFormat::CoreProfile);
    format.setSwapInterval(1);
    format.setDepth(true);
    setFormat(format);
    // Default value
    image_bmp = QString("image/sun.bmp");
    image_obj = QString("image/sun.obj");
    current_vs = QString("Shader/flat_vertexShader.vs");
    current_fs = QString("Shader/flat_fragmentShader.frag");
    current_value = 0;
    filter = 0;
    // Setting Timer to update
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1);
}

MyOpenGL::~MyOpenGL()
{
    program->destroyed();
}

QOpenGLShaderProgram* MyOpenGL::setup_shader(const char *vertex_shader, const char *fragment_shader)
{
    // Load the vertex shader
    QOpenGLShader *vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
    vertexShader->compileSourceFile(vertex_shader);

    // Load the fragment shader
    QOpenGLShader *fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
    fragmentShader->compileSourceFile(fragment_shader);

    // add the shader in program
    QOpenGLShaderProgram *program = new QOpenGLShaderProgram();
    program->addShader(vertexShader);
    program->addShader(fragmentShader);

    // Link the shader
    program->link();

    return program;
}

int MyOpenGL::add_obj(QOpenGLShaderProgram *program, const char *filename, const char *texbmp)
{

    Object_struct *new_node = new Object_struct();
    vector<tinyobj::shape_t> shapes;
    vector<tinyobj::material_t> materials;

    string err = tinyobj::LoadObj(shapes, materials, filename);
    if (!err.empty()||shapes.size()==0)
    {
        cerr<<err<<endl;
        exit(1);
    }

    // Program
    new_node->program = program;

    // Generate VAO
    new_node->vao = new QOpenGLVertexArrayObject();
    new_node->vao->create();
    new_node->vao->bind();

    // Generate VBO - position
    new_node->vbo_position = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    new_node->vbo_position->create();
    new_node->vbo_position->setUsagePattern(QOpenGLBuffer::StaticDraw);
    new_node->vbo_position->bind();
    new_node->vbo_position->allocate(shapes[0].mesh.positions.data(),sizeof(GLfloat) * shapes[0].mesh.positions.size());
    //new_node->vbo_position->write(0,shapes[0].mesh.positions.data(),sizeof(GLfloat) * shapes[0].mesh.positions.size());
    new_node->program->enableAttributeArray(0);
    new_node->program->setAttributeBuffer(0,GL_FLOAT,0,3);
    // Generate VBO - texture
    if(shapes[0].mesh.texcoords.size() > 0)
    {
        // Using QOpenGLBuffer::PixelUnpackBuffer
        new_node->vbo_texture = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
        new_node->vbo_texture->create();
        new_node->vbo_texture->setUsagePattern(QOpenGLBuffer::StaticDraw);
        new_node->vbo_texture->bind();
        new_node->vbo_texture->allocate(shapes[0].mesh.texcoords.data(),sizeof(GLfloat)*shapes[0].mesh.texcoords.size());
        //new_node->vbo_texture->write(0,shapes[0].mesh.texcoords.data(),sizeof(GLfloat)*shapes[0].mesh.texcoords.size());
        new_node->program->enableAttributeArray(1);
        new_node->program->setAttributeBuffer(1,GL_FLOAT,0,2);
        // Load pic
        new_node->texture = new QOpenGLTexture(QImage(texbmp).mirrored());
        new_node->texture->setMinMagFilters(QOpenGLTexture::LinearMipMapNearest , QOpenGLTexture::Linear);
        new_node->texture->generateMipMaps();
    }
    // Generate VBO - normals
    if(shapes[0].mesh.normals.size() > 0)
    {
        new_node->vbo_normals = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
        new_node->vbo_normals->create();
        new_node->vbo_normals->setUsagePattern(QOpenGLBuffer::StaticDraw);
        new_node->vbo_normals->bind();
        new_node->vbo_normals->allocate(shapes[0].mesh.normals.data(),sizeof(GLfloat)*shapes[0].mesh.normals.size());
        //new_node->vbo_normals->write(0,shapes[0].mesh.normals.data(),sizeof(GLfloat)*shapes[0].mesh.normals.size());
        new_node->program->enableAttributeArray(2);
        new_node->program->setAttributeBuffer(2,GL_FLOAT,0,3);
    }
    // Generate VBO - index
    new_node->vbo_indices = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    new_node->vbo_indices->create();
    new_node->vbo_indices->setUsagePattern(QOpenGLBuffer::StaticDraw);
    new_node->vbo_indices->bind();
    new_node->vbo_indices->allocate(shapes[0].mesh.indices.data(),sizeof(GLuint)*shapes[0].mesh.indices.size());
    //new_node->vbo_indices->write(0,shapes[0].mesh.indices.data(),sizeof(GLuint)*shapes[0].mesh.indices.size());

    indicesCount.push_back(shapes[0].mesh.indices.size());

    // Unbind VAO
    new_node->vao->release();

    objects.push_back(new_node);

    return (objects.size()-1);
}

void MyOpenGL::setColorAttr(QOpenGLShaderProgram *program, const QVector3D LightPos, const QVector3D camera)
{
    // Fetch and set light Color
    GLint lightColorLoc = program->uniformLocation("lightColor");
    program->setUniformValue(lightColorLoc,QVector3D(1.0f,1.0f,1.0f));
    // Fetch and set light Position
    GLint lightPosLoc = program->uniformLocation("lightPos");
    program->setUniformValue(lightPosLoc,LightPos.x(),LightPos.y(),LightPos.z());
    // Set View
    GLint viewPosLoc = program->uniformLocation("viewPos");
    program->setUniformValue(viewPosLoc,camera.x(),camera.y(),camera.z());
}

void MyOpenGL::setVS(QOpenGLShaderProgram *program, const QMatrix4x4 projection, const QMatrix4x4 view, const QMatrix4x4 model)
{
    setUniformMat4(program,"projection",projection);
    setUniformMat4(program,"vp",view);
    setUniformMat4(program,"model",model);
}

void MyOpenGL::setUniformMat4(QOpenGLShaderProgram *program, const string &name, const QMatrix4x4 mat)
{
    program->bind();
    GLint loc = program->uniformLocation(name.c_str());
    if(loc == -1)return;
    program->setUniformValue(loc,mat);
}

void MyOpenGL::reloadShader(const char *vertex_shader, const char *fragment_shader, const char *pic_obj, const char *pic_src)
{
    // Need to destroy the old program
    releaseObject();

    program = new QOpenGLShaderProgram();

    program = setup_shader(vertex_shader,fragment_shader);

    sun = add_obj(program,pic_obj,pic_src);

    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);
}

void MyOpenGL::releaseObject()
{
    for(int i=0;i<objects.size();i++){
        // Release the VAO
        objects[i]->vao->release();
        // Release the Texture sampler
        objects[i]->texture->release();
        // Release the VBO
        objects[i]->vbo_indices->release();
        objects[i]->vbo_normals->release();
        objects[i]->vbo_position->release();
        objects[i]->vbo_texture->release();
        // Delete the original Program
        objects[i]->program->removeAllShaders();
        objects[i]->program->release();
        objects[i]->program->destroyed();
        // Pop out the objects
        objects.pop_back();
    }
}

void MyOpenGL::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i = 0; i < objects.size() ; i++)
    {
        // glUseProgram
        objects[i]->program->bind();
        // glBindVertexArray
        objects[i]->vao->bind();
        // glBindTexture
        objects[i]->texture->bind();
        // Draw Element
        glDrawElements(GL_TRIANGLES,indicesCount[i],GL_UNSIGNED_INT, NULL);
        objects[i]->vao->release();
    }
}

void MyOpenGL::mousePressEvent(QMouseEvent *e)
{
    // Get the place what we need to blur

    cout<< "Press"<< e->pos().x() << endl;
}

void MyOpenGL::changeShader(QString string)
{
    if(string == QString("Flat Shading Model"))
    {   
        // Reload the Flat Shading Model
        current_vs = QString("Shader/flat_vertexShader.vs");
        current_fs = QString("Shader/flat_fragmentShader.frag");
        cout<< "Flat OK" << endl;
    }
    else if(string == QString("Gourand Shading Model"))
    {
        // Reload the Flat Shading Model
        current_vs = QString("Shader/gourand_vertexShader.vs");
        current_fs = QString("Shader/gourand_fragmentShader.frag");
        cout<< "Gourand OK" << endl;
    }
    else if(string == QString("Phong Shading Model"))
    {
        // Reload the Phong Shading Model
        current_vs = QString("Shader/vertexShader.vs");
        current_fs = QString("Shader/fragmentShader.frag");
        cout<< "Phong OK" << endl;
    }
    else if(string == QString("Blinn-Phong Shading Model"))
    {
        // Reload the Blinn-Phong Shading Model
        current_vs = QString("Shader/Blinn_vertexShader.vs");
        current_fs = QString("Shader/Blinn_fragmentShader.frag");
        cout<< "Blinn-Phong OK" << endl;
    }
    else{
        // Exception
        cout << "Exception Handler" << endl;
    }
    reloadShader(current_vs.toStdString().c_str(),current_fs.toStdString().c_str(),image_obj.toStdString().c_str(),image_bmp.toStdString().c_str());
}

void MyOpenGL::changeViewShader(int value)
{
    // reset the camera
    camera = QVector3D((float)value/3,(float)value/3,(float)value/3);
}

void MyOpenGL::changeLightXPos(int value)
{
    lightPosition.setX((float)value);
}

void MyOpenGL::changeLightYPos(int value)
{
    lightPosition.setY((float)value);
}

void MyOpenGL::changeLightZPos(int value)
{
    lightPosition.setZ((float)value);
}

void MyOpenGL::changePicSrc(QString string)
{
    if(filter == 0)
    {
        temp_image = string;
        filter++;
    }
    else
    {
        image_bmp = string;
        image_obj = temp_image;
        reloadShader(current_vs.toStdString().c_str(),current_fs.toStdString().c_str(),temp_image.toStdString().c_str(),string.toStdString().c_str());
        filter  = 0;
    }
}

void MyOpenGL::changePicObj(QString string)
{
    if(filter == 0)
    {
        temp_image = string;
        filter++;
    }
    else
    {
        image_bmp = temp_image;
        image_obj = string;
        reloadShader(current_vs.toStdString().c_str(),current_fs.toStdString().c_str(),image_obj.toStdString().c_str(),image_bmp.toStdString().c_str());
        filter  = 0;
    }
}

void MyOpenGL::initializeGL()
{
    // Setup the rendering context , define display lists
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    program = setup_shader("Shader/flat_vertexShader.vs","Shader/flat_fragmentShader.frag");
    sun = add_obj(program , "image/sun.obj" , "image/sun.bmp");
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);
    // Setting light Position , camera Location
    lightPosition = QVector3D(10.0f,10.0f,10.0f);
    camera = QVector3D(30.0f , 30.0f , 30.0f);
}

void MyOpenGL::resizeGL(int width, int height)
{
    // Setup viewport,projection ...
    glViewport(0, 0, width, height);
    QMatrix4x4 proj;
    proj.perspective(45.0f,640.0f/480,1.0f,100.0f);
    QMatrix4x4 view;
    view.lookAt(camera,QVector3D(0,0,0),QVector3D(0,1,0));
    QMatrix4x4 model;
    model.scale(1.0f);
    setVS(program,proj,view,model);
    // Draw the scene - render (start)
    render();
    // render (end)
}

void MyOpenGL::paintGL()
{
    // When User call update , update will trigger paintGL()
    // Using an increasing integer to replace glfwGetTime()
    current_value++;
    // ReColor
    setColorAttr(program,lightPosition,camera);
    QMatrix4x4 proj;
    proj.perspective(45.0f,640.0f/480,1.0f,100.0f);
    QMatrix4x4 view;
    view.lookAt(camera,QVector3D(0,0,0),QVector3D(0,1,0));
    QMatrix4x4 model;
    // Setting Rotate
    model.rotate((float)current_value*0.01f,0,1,0);
    // Transmit the matrices into shader
    setVS(program,proj,view,model);
    // Draw the scene - render (start)
    render();
    // render (end)
}

