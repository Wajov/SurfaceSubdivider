#ifndef DOO_SABIN_SUBDIVIDER_H
#define DOO_SABIN_SUBDIVIDER_H

#include <vector>

#include <QVector3D>

#include "Subdivider.h"

class DooSabinSubdivider : public Subdivider {
public:
    DooSabinSubdivider();
    ~DooSabinSubdivider() override;
    void subdivide(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) override;
};

#endif