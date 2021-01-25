#include "CatmullClarkSubdivider.h"

CatmullClarkSubdivider::CatmullClarkSubdivider() : Subdivider() {}

CatmullClarkSubdivider::~CatmullClarkSubdivider() {}

void CatmullClarkSubdivider::subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    std::vector<unsigned int> facetVertices;
    for (int i = 0; i < starts.size(); i++) {
        QVector3D facetVertex(0.0f, 0.0f, 0.0f);
        for (unsigned int j = 0, halfedge = starts[i]; j < size[i]; j++, halfedge = succ[halfedge])
            facetVertex += this->vertices[halfedges[halfedge]];
        facetVertices.push_back(vertices.size());
        vertices.push_back(facetVertex / size[i]);
    }
    std::vector<unsigned int> edgeVertices(halfedges.size(), UINT_MAX);
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (edgeVertices[i] == UINT_MAX) {
            edgeVertices[i] = edgeVertices[opposite[i]] = vertices.size();
            vertices.push_back(((this->vertices[halfedges[i]] + this->vertices[halfedges[succ[i]]]) / 2 + vertices[facetVertices[facet[i]]] + vertices[facetVertices[facet[opposite[i]]]]) / 3);
        }
    std::vector<unsigned int> vertexVertices(halfedges.size(), UINT_MAX);
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (vertexVertices[i] == UINT_MAX) {
            unsigned int j = i;
            QVector3D q(0.0f, 0.0f, 0.0f), r(0.0f, 0.0f, 0.0f);
            int n = 0;
            do {
                q += vertices[facetVertices[facet[j]]];
                r += (this->vertices[halfedges[j]] + this->vertices[halfedges[succ[j]]]) / 2;
                n++;
                j = opposite[pred[j]];
            } while (j != i);
            q /= (float)n;
            r /= (float)n;
            QVector3D vertexVertex = (q + 2 * r + (float)(n - 3) * this->vertices[halfedges[i]]) / (float)n;
            j = i;
            do {
                vertexVertices[j] = vertices.size();
                j = opposite[pred[j]];
            } while (j != i);
            vertices.push_back(vertexVertex);
        }

    bool *flag = new bool[halfedges.size()];
    memset(flag, false, halfedges.size() * sizeof(bool));
    for (unsigned int i = 0; i < halfedges.size(); i++)
        if (!flag[i]) {
            unsigned int j = i;
            do {
                flag[j] = true;
                indices.push_back({vertexVertices[j], edgeVertices[j], facetVertices[facet[j]], edgeVertices[opposite[pred[j]]]});
                j = opposite[pred[j]];
            } while (j != i);
        }
    delete[] flag;
}