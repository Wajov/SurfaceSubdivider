#ifndef HALFEDGE_H
#define HALFEDGE_H

class Halfedge {
private:
    unsigned int source, target;

public:
    Halfedge(unsigned source, unsigned int target);
    ~Halfedge();
    unsigned int getSource();
    unsigned int getTarget();
};

#endif