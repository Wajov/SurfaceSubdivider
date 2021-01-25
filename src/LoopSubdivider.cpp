#include "LoopSubdivider.h"

LoopSubdivider::LoopSubdivider() :Subdivider() {}

LoopSubdivider::~LoopSubdivider() {}

void LoopSubdivider::construct(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    std::vector<std::vector<unsigned int>> newIndices;
    for (std::vector<unsigned int> &index : indices)
        for (int i = 1; i < index.size() - 1; i++)
            newIndices.push_back({index[0], index[i], index[i + 1]});
    Subdivider::construct(vertices, newIndices);
}

void LoopSubdivider::subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    std::vector<unsigned int> edgeVertices(halfedges.size(), UINT_MAX);
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (edgeVertices[i] == UINT_MAX) {
            edgeVertices[i] = edgeVertices[opposite[i]] = vertices.size();
            vertices.push_back(((this->vertices[halfedges[i]] + this->vertices[halfedges[succ[i]]]) * 3 + this->vertices[halfedges[succ[succ[i]]]] + this->vertices[halfedges[succ[succ[opposite[i]]]]]) / 8);
        }
    std::vector<unsigned int> vertexVertices(halfedges.size(), UINT_MAX);
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (vertexVertices[i] == UINT_MAX) {
            unsigned int j = i;
            int k = 0;
            do {
                k++;
                j = opposite[pred[j]];
            } while (j != i);
            float t = std::cos(2.0f * (float)M_PI / (float)k) / 4.0f + 3.0f / 8.0f;
            float beta = (t * t + 3.0f / 8.0f) / (float)k;
            QVector3D vertexVertex = (1.0f - (float)k * beta) * this->vertices[halfedges[i]];
            j = i;
            do {
                vertexVertex += beta * this->vertices[halfedges[succ[j]]];
                j = opposite[pred[j]];
            } while (j != i);
            j = i;
            do {
                vertexVertices[j] = vertices.size();
                j = opposite[pred[j]];
            } while (j != i);
            vertices.push_back(vertexVertex);
        }

    for (int i = 0; i < size.size(); i++) {
        for (unsigned int j = 0, halfedge = starts[i]; j < size[i]; j++, halfedge = succ[halfedge])
            indices.push_back({vertexVertices[halfedge], edgeVertices[halfedge], edgeVertices[pred[halfedge]]});
        indices.push_back({edgeVertices[starts[i]], edgeVertices[succ[starts[i]]], edgeVertices[pred[starts[i]]]});
    }
}