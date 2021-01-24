#include "Mesh.h"
#include <iostream>
Mesh::Mesh() {
    QVector3D v0(-1.0f, -1.0f, -1.0f);
    QVector3D v1(-1.0f, -1.0f, 1.0f);
    QVector3D v2(-1.0f, 1.0f, -1.0f);
    QVector3D v3(-1.0f, 1.0f, 1.0f);
    QVector3D v4(1.0f, -1.0f, -1.0f);
    QVector3D v5(1.0f, -1.0f, 1.0f);
    QVector3D v6(1.0f, 1.0f, -1.0f);
    QVector3D v7(1.0f, 1.0f, 1.0f);
    vertices = {Vertex(v0), Vertex(v1), Vertex(v2), Vertex(v3), Vertex(v4), Vertex(v5), Vertex(v6), Vertex(v7)};

    std::vector<unsigned int> f0 = {0, 4, 5, 1};
    std::vector<unsigned int> f1 = {1, 5, 7, 3};
    std::vector<unsigned int> f2 = {4, 6, 7, 5};
    std::vector<unsigned int> f3 = {0, 2, 6, 4};
    std::vector<unsigned int> f4 = {0, 1, 3, 2};
    std::vector<unsigned int> f5 = {2, 3, 7, 6};
    std::vector<std::vector<unsigned int>> indices = {f0, f1, f2, f3, f4, f5};

    construct(indices);
}

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    this->vertices = vertices;
    construct(indices);
}

Mesh::~Mesh() {
    delete edgeVAO;
    delete facetVAO;
}

void Mesh::construct(std::vector<std::vector<unsigned int>> &indices) {
    edgeVAO = facetVAO = nullptr;

    std::map<std::pair<unsigned int, unsigned int>, unsigned int> edges;
    for (std::vector<unsigned int> index : indices) {
        unsigned int begin = halfedges.size();
        start.push_back(begin);
        for (int i = 0; i < index.size() - 1; i++) {
            edges.insert(std::make_pair(std::make_pair(index[i], index[i + 1]), halfedges.size()));
            halfedges.push_back(Halfedge(index[i], index[i + 1]));
            opposite.push_back(UINT_MAX);
            auto iter = edges.find(std::make_pair(index[i + 1], index[i]));
            if (iter != edges.end()) {
                opposite[opposite.size() - 1] = iter->second;
                opposite[iter->second] = opposite.size() - 1;
            }
        }
        edges.insert(std::make_pair(std::make_pair(index[index.size() - 1], index[0]), halfedges.size()));
        halfedges.push_back(Halfedge(index[index.size() - 1], index[0]));
        opposite.push_back(UINT_MAX);
        auto iter = edges.find(std::make_pair(index[0], index[index.size() - 1]));
        if (iter != edges.end()) {
            opposite[opposite.size() - 1] = iter->second;
            opposite[iter->second] = opposite.size() - 1;
        }
        unsigned int end = halfedges.size();
        pred.push_back(end - 1);
        for (int i = begin + 1; i < end; i++)
            pred.push_back(i - 1);
        for (int i = begin; i < end - 1; i++)
            succ.push_back(i + 1);
        succ.push_back(begin);

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

void Mesh::bind(QOpenGLShaderProgram &edgeProgram, QOpenGLShaderProgram &facetProgram) {
    initializeOpenGLFunctions();

    edgeVAO = new QOpenGLVertexArrayObject();
    QOpenGLVertexArrayObject::Binder edgeBinder(edgeVAO);

    edgeVBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    edgeVBO.create();
    edgeVBO.bind();
    edgeVBO.allocate(&(vertices[0]), vertices.size() * sizeof(Vertex));

    edgeEBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    edgeEBO.create();
    edgeEBO.bind();
    edgeEBO.allocate(&(edgeIndices[0]), edgeIndices.size() * sizeof(unsigned int));

    int edgeAttributePosition = edgeProgram.attributeLocation("position");
    edgeProgram.setAttributeBuffer(edgeAttributePosition, GL_FLOAT, offsetof(Vertex, position), 3, sizeof(Vertex));
    edgeProgram.enableAttributeArray(edgeAttributePosition);

    int edgeAttributeNormal = edgeProgram.attributeLocation("normal");
    edgeProgram.setAttributeBuffer(edgeAttributeNormal, GL_FLOAT, offsetof(Vertex, normal), 3, sizeof(Vertex));
    edgeProgram.enableAttributeArray(edgeAttributeNormal);

    facetVAO = new QOpenGLVertexArrayObject();
    QOpenGLVertexArrayObject::Binder facetBinder(facetVAO);

    facetVBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    facetVBO.create();
    facetVBO.bind();
    facetVBO.allocate(&(vertices[0]), vertices.size() * sizeof(Vertex));

    facetEBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    facetEBO.create();
    facetEBO.bind();
    facetEBO.allocate(&(facetIndices[0]), facetIndices.size() * sizeof(unsigned int));

    int attributePosition = facetProgram.attributeLocation("position");
    facetProgram.setAttributeBuffer(attributePosition, GL_FLOAT, offsetof(Vertex, position), 3, sizeof(Vertex));
    facetProgram.enableAttributeArray(attributePosition);

    int attributeNormal = facetProgram.attributeLocation("normal");
    facetProgram.setAttributeBuffer(attributeNormal, GL_FLOAT, offsetof(Vertex, normal), 3, sizeof(Vertex));
    facetProgram.enableAttributeArray(attributeNormal);
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

Mesh Mesh::subdivisionDooSabin() {
    std::vector<Vertex> vertices;
    for (unsigned int startHalfedge : start) {
        std::vector<QVector3D> edgeVertices;
        QVector3D facetVertex(0.0f, 0.0f, 0.0f);
        unsigned int halfedge = startHalfedge;
        do {
            edgeVertices.push_back((this->vertices[halfedges[halfedge].getSource()].position + this->vertices[halfedges[halfedge].getTarget()].position) / 2.0f);
            facetVertex += this->vertices[halfedges[halfedge].getSource()].position;
            halfedge = succ[halfedge];
        } while (halfedge != startHalfedge);
        facetVertex /= (float)edgeVertices.size();

        int i = 0;
        do {
            QVector3D position = (this->vertices[halfedges[halfedge].getSource()].position + edgeVertices[i > 0 ? i - 1 : edgeVertices.size() - 1] + edgeVertices[i] + facetVertex) / 4.0f;
            vertices.push_back(Vertex(position));
            i++;
            halfedge = succ[halfedge];
        } while (halfedge != startHalfedge);
    }
    std::cout << vertices.size() << std::endl;

    std::vector<std::vector<unsigned int>> indices;
    for (unsigned int startHalfedge : start) {
        unsigned int halfedge = startHalfedge;
        std::vector<unsigned int> index;
        do {
            index.push_back(halfedge);
            halfedge = succ[halfedge];
        } while (halfedge != startHalfedge);
        indices.push_back(index);
    }
    bool *flag = new bool[halfedges.size()];
    memset(flag, false, halfedges.size() * sizeof(bool));
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (!flag[i]) {
            flag[i] = flag[opposite[i]] = true;
            indices.push_back({i, succ[opposite[i]], opposite[i], succ[i]});
        }
    memset(flag, false, halfedges.size() * sizeof(bool));
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (!flag[i]) {
            unsigned int j = i;
            std::vector<unsigned int> index;
            do {
                flag[j] = true;
                index.push_back(j);
                j = opposite[pred[j]];
            } while (j != i);
            indices.push_back(index);
        }

    return Mesh(vertices, indices);
}