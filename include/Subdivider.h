#ifndef SUBDIVIDER_H
#define SUBDIVIDER_H

#include <climits>
#include <vector>
#include <map>

#include <QVector3D>

class Subdivider {
protected:
    std::vector<QVector3D> vertices;
    std::vector<unsigned int> halfedges, facet, starts, size, pred, succ, opposite;

public:
    Subdivider();
    virtual ~Subdivider();
    virtual void construct(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices);
    virtual void subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) = 0;
};

#endif