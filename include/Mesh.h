#ifndef MESH_H
#define MESH_H

#include <climits>
#include <vector>
#include <map>

#include <QVector3D>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include "Subdivider.h"

class Mesh : protected QOpenGLFunctions {
private:
    std::vector<QVector3D> vertices;
    std::vector<std::vector<unsigned int>> indices;
    std::vector<unsigned int> edgeIndices, facetIndices;
    QOpenGLVertexArrayObject *edgeVAO, *facetVAO;
    QOpenGLBuffer edgeVBO, edgeEBO, facetVBO, facetEBO;
    void construct(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices);

public:
    Mesh();
    Mesh(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices);
    ~Mesh();
    int numberOfVertices();
    int numberOfFacets();
    void bind(QOpenGLShaderProgram &edgeProgram, QOpenGLShaderProgram &facetProgram);
    void renderEdge();
    void renderFacet();
    Mesh subdivide(Subdivider *subdivider);
};

#endif