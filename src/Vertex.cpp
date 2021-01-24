#include "Vertex.h"

Vertex::Vertex(QVector3D &position) {
    this->position = position;
}

Vertex::Vertex(QVector3D &position, QVector3D &normal) {
    this->position = position;
    this->normal = normal;
}

Vertex::~Vertex() {}