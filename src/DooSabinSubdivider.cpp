#include "DooSabinSubdivider.h"

DooSabinSubdivider::DooSabinSubdivider() : Subdivider() {}

DooSabinSubdivider::~DooSabinSubdivider() {}

void DooSabinSubdivider::subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    for (int i = 0; i < starts.size(); i++) {
        std::vector<QVector3D> edgeVertices;
        QVector3D facetVertex(0.0f, 0.0f, 0.0f);
        for (unsigned int j = 0, halfedge = starts[i]; j < size[i]; j++, halfedge = succ[halfedge]) {
            edgeVertices.push_back((this->vertices[halfedges[halfedge]] + this->vertices[halfedges[succ[halfedge]]]) / 2.0f);
            facetVertex += this->vertices[halfedges[halfedge]];
        }
        facetVertex /= size[i];

        for (unsigned int j = 0, halfedge = starts[i]; j < size[i]; j++, halfedge = succ[halfedge])
            vertices.push_back((this->vertices[halfedges[halfedge]] + edgeVertices[j > 0 ? j - 1 : edgeVertices.size() - 1] + edgeVertices[j] + facetVertex) / 4.0f);
    }

    for (int i = 0; i < starts.size(); i++) {
        std::vector<unsigned int> index;
        for (unsigned int j = 0, halfedge = starts[i]; j < size[i]; j++, halfedge = succ[halfedge])
            index.push_back(halfedge);
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
    delete[] flag;
}