#ifndef CATMULL_CLARK_SUBDIVIDER_H
#define CATMULL_CLARK_SUBDIVIDER_H

#include <climits>
#include <vector>

#include <QVector3D>

#include "Subdivider.h"

class CatmullClarkSubdivider : public Subdivider {
public:
    CatmullClarkSubdivider();
    ~CatmullClarkSubdivider() override;
    void subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) override;
};

#endif