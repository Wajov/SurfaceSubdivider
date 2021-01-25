#ifndef LOOP_SUBDIVIDER_H
#define LOOP_SUBDIVIDER_H

#include <climits>
#include <cmath>
#include <vector>

#include <QVector3D>

#include "Subdivider.h"

class LoopSubdivider : public Subdivider {
public:
    LoopSubdivider();
    ~LoopSubdivider() override;
    void construct(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) override;
    void subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) override;
};

#endif