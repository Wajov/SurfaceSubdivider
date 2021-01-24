#include "Halfedge.h"

Halfedge::Halfedge(unsigned int source, unsigned int target) {
    this->source = source;
    this->target = target;
}

Halfedge::~Halfedge() {}

unsigned int Halfedge::getSource() {
    return source;
}

unsigned int Halfedge::getTarget() {
    return target;
}