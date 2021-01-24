#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>

class Vertex {
public:
    QVector3D position, normal;
    Vertex(QVector3D &position);
    Vertex(QVector3D &position, QVector3D &normal);
    ~Vertex();
};

#endif