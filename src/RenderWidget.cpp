#include "RenderWidget.h"

RenderWidget::RenderWidget(QWidget *parent, Mesh &mesh) : QOpenGLWidget(parent) {
    press = false;
    factor = 1.0f;
    this->mesh = mesh;
}

RenderWidget::~RenderWidget() {}

void RenderWidget::initializeGL() {
    initializeOpenGLFunctions();

    edgeProgram.setParent(this);
    if (!edgeProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "shader/VertexShader.glsl")) {
        std::cerr << "Failed to add vertex shader" << std::endl;
        return;
    }
    if (!edgeProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "shader/EdgeFragmentShader.glsl")) {
        std::cerr << "Failed to add fragment shader" << std::endl;
        return;
    }
    if (!edgeProgram.link()) {
        std::cerr << "Failed to link shader program" << std::endl;
        return;
    }

    facetProgram.setParent(this);
    if (!facetProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "shader/VertexShader.glsl")) {
        std::cerr << "Failed to add vertex shader" << std::endl;
        return;
    }
    if (!facetProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "shader/FacetFragmentShader.glsl")) {
        std::cerr << "Failed to add fragment shader" << std::endl;
        return;
    }
    if (!facetProgram.link()) {
        std::cerr << "Failed to link shader program" << std::endl;
        return;
    }

    glEnable(GL_DEPTH_TEST);
    mesh.bind(edgeProgram, facetProgram);
}

void RenderWidget::paintGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QVector3D lightPosition(2.0f, 2.0f, 2.0f), cameraPosition(0.0f, 0.0f, 5.0f);
    QMatrix4x4 modelMat, viewMat, projectionMat;
    modelMat = rotate;
    modelMat.scale(factor);
    viewMat.lookAt(cameraPosition, QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f));
    projectionMat.perspective(45.0f, (float)width() / (float)height(), 0.1f, 100.0f);

    edgeProgram.bind();
    edgeProgram.setUniformValue("model", modelMat);
    edgeProgram.setUniformValue("view", viewMat);
    edgeProgram.setUniformValue("projection", projectionMat);
    mesh.renderEdge();

    facetProgram.bind();
    facetProgram.setUniformValue("model", modelMat);
    facetProgram.setUniformValue("view", viewMat);
    facetProgram.setUniformValue("projection", projectionMat);
    facetProgram.setUniformValue("lightPosition", lightPosition);
    facetProgram.setUniformValue("cameraPosition", cameraPosition);
    mesh.renderFacet();
}

void RenderWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void RenderWidget::mousePressEvent(QMouseEvent *event) {
    press = true;
    lastX = lastY = INT_MIN;
}

void RenderWidget::mouseReleaseEvent(QMouseEvent *event) {
    press = false;
}

void RenderWidget::mouseMoveEvent(QMouseEvent *event) {
    if (press && lastX != INT_MIN && lastY != INT_MIN && (event->x() != lastX || event->y() != lastY)) {
        QVector3D a = QVector3D((float)lastX / (float)width() - 0.5f, 0.5f - (float)lastY / (float)height(), 1.0f).normalized();
        QVector3D b = QVector3D((float)event->x() / (float)width() - 0.5f, 0.5f - (float)event->y() / (float)height(), 1.0f).normalized();
        QVector3D axis = QVector3D::crossProduct(a, b);
        float angle = std::acos(QVector3D::dotProduct(a, b));
        QMatrix4x4 temp;
        temp.rotate(angle / (float)M_PI * 1800.0f, axis);
        rotate = temp * rotate;
    }

    lastX = event->x();
    lastY = event->y();
    update();
}

void RenderWidget::wheelEvent(QWheelEvent *event) {
    factor += (float)event->angleDelta().y() * 1e-3f;
    factor = std::max(factor, 0.01f);
    update();
}