#ifndef RENDER_WIDGET_H
#define RENDER_WIDGET_H

#include <cmath>
#include <climits>
#include <iostream>

#include <QVector3D>
#include <QMatrix4x4>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QWheelEvent>

#include "Mesh.h"

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
private:
    bool press;
    int lastX, lastY;
    float factor;
    QMatrix4x4 rotate;
    Mesh mesh;
    QOpenGLShaderProgram edgeProgram, facetProgram;
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

public:
    RenderWidget(QWidget *parent, Mesh &mesh);
    ~RenderWidget() override;
};

#endif