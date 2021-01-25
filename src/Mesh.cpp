#include "Mesh.h"

Mesh::Mesh() {
    QVector3D v0(-1.0f, -1.0f, -1.0f);
    QVector3D v1(-1.0f, -1.0f, 1.0f);
    QVector3D v2(-1.0f, 1.0f, -1.0f);
    QVector3D v3(-1.0f, 1.0f, 1.0f);
    QVector3D v4(1.0f, -1.0f, -1.0f);
    QVector3D v5(1.0f, -1.0f, 1.0f);
    QVector3D v6(1.0f, 1.0f, -1.0f);
    QVector3D v7(1.0f, 1.0f, 1.0f);
    std::vector<QVector3D> vertices = {v0, v1, v2, v3, v4, v5, v6, v7};

    std::vector<unsigned int> f0 = {0, 4, 5, 1};
    std::vector<unsigned int> f1 = {1, 5, 7, 3};
    std::vector<unsigned int> f2 = {4, 6, 7, 5};
    std::vector<unsigned int> f3 = {2, 6, 4, 0};
    std::vector<unsigned int> f4 = {1, 3, 2, 0};
    std::vector<unsigned int> f5 = {3, 7, 6, 2};
    std::vector<std::vector<unsigned int>> indices = {f0, f1, f2, f3, f4, f5};

    construct(vertices, indices);
}

Mesh::Mesh(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    construct(vertices,indices);
}

Mesh::~Mesh() {
    delete edgeVAO;
    delete facetVAO;
}

void Mesh::construct(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    this->vertices = vertices;
    this->indices = indices;
    edgeVAO = facetVAO = nullptr;
    for (std::vector<unsigned int> index : this->indices) {
        for (int i = 0; i < index.size() - 1; i++) {
            edgeIndices.push_back(index[i]);
            edgeIndices.push_back(index[i + 1]);
        }
        edgeIndices.push_back(index[index.size() - 1]);
        edgeIndices.push_back(index[0]);

        for (int i = 1; i < index.size() - 1; i++) {
            facetIndices.push_back(index[0]);
            facetIndices.push_back(index[i]);
            facetIndices.push_back(index[i + 1]);
        }
    }
}

int Mesh::numberOfVertices() {
    return vertices.size();
}

int Mesh::numberOfFacets() {
    return indices.size();
}

void Mesh::bind(QOpenGLShaderProgram &edgeProgram, QOpenGLShaderProgram &facetProgram) {
    initializeOpenGLFunctions();

    edgeVAO = new QOpenGLVertexArrayObject();
    QOpenGLVertexArrayObject::Binder edgeBinder(edgeVAO);

    edgeVBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    edgeVBO.create();
    edgeVBO.bind();
    edgeVBO.allocate(&(vertices[0]), vertices.size() * sizeof(QVector3D));

    edgeEBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    edgeEBO.create();
    edgeEBO.bind();
    edgeEBO.allocate(&(edgeIndices[0]), edgeIndices.size() * sizeof(unsigned int));

    int edgeAttribute = edgeProgram.attributeLocation("position");
    edgeProgram.setAttributeBuffer(edgeAttribute, GL_FLOAT, 0, 3, sizeof(QVector3D));
    edgeProgram.enableAttributeArray(edgeAttribute);

    facetVAO = new QOpenGLVertexArrayObject();
    QOpenGLVertexArrayObject::Binder facetBinder(facetVAO);

    facetVBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    facetVBO.create();
    facetVBO.bind();
    facetVBO.allocate(&(vertices[0]), vertices.size() * sizeof(QVector3D));

    facetEBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    facetEBO.create();
    facetEBO.bind();
    facetEBO.allocate(&(facetIndices[0]), facetIndices.size() * sizeof(unsigned int));

    int facetAttribute = facetProgram.attributeLocation("position");
    facetProgram.setAttributeBuffer(facetAttribute, GL_FLOAT, 0, 3, sizeof(QVector3D));
    facetProgram.enableAttributeArray(facetAttribute);
}

void Mesh::renderEdge() {
    QOpenGLVertexArrayObject::Binder edgeBinder(edgeVAO);
    glLineWidth(3.0f);
    glDrawElements(GL_LINES, edgeIndices.size(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::renderFacet() {
    QOpenGLVertexArrayObject::Binder facetBinder(facetVAO);
    glDrawElements(GL_TRIANGLES, facetIndices.size(), GL_UNSIGNED_INT, nullptr);
}

Mesh Mesh::subdivide(Subdivider *subdivider) {
    std::vector<QVector3D> vertices;
    std::vector<std::vector<unsigned int>> indices;
    subdivider->construct(this->vertices, this->indices);
    subdivider->subdivide(vertices, indices);

    return Mesh(vertices, indices);
}