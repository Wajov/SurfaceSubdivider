#ifndef MESH_H
#define MESH_H

#include <climits>
#include <vector>
#include <map>

#include <QImage>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include "Vertex.h"
#include "Halfedge.h"

class Mesh : protected QOpenGLFunctions {
private:
    std::vector<Vertex> vertices;
    std::vector<Halfedge> halfedges;
    std::vector<unsigned int> start, pred, succ, opposite;
    std::vector<unsigned int> edgeIndices, facetIndices;
    QOpenGLVertexArrayObject *edgeVAO, *facetVAO;
    QOpenGLBuffer edgeVBO, edgeEBO, facetVBO, facetEBO;
    void construct(std::vector<std::vector<unsigned int>> &indices);

public:
    Mesh();
    Mesh(std::vector<Vertex> &vertices, std::vector<std::vector<unsigned int>> &indices);
    ~Mesh();
    void bind(QOpenGLShaderProgram &edgeProgram, QOpenGLShaderProgram &facetProgram);
    void renderEdge();
    void renderFacet();
    Mesh subdivisionDooSabin();
};

#endif