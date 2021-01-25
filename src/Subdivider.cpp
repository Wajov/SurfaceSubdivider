#include "Subdivider.h"

Subdivider::Subdivider() {}

Subdivider::~Subdivider() {}

void Subdivider::construct(std::vector<QVector3D> &vertices, std::vector<std::vector<unsigned int>> &indices) {
    this->vertices = vertices;
    std::map<std::pair<unsigned int, unsigned int>, unsigned int> edges;
    for (std::vector<unsigned int> index : indices) {
        unsigned int begin = halfedges.size();
        starts.push_back(begin);
        for (int i = 0; i < index.size() - 1; i++) {
            edges.insert(std::make_pair(std::make_pair(index[i], index[i + 1]), halfedges.size()));
            halfedges.push_back(index[i]);
            facet.push_back(size.size());
            opposite.push_back(UINT_MAX);
            auto iter = edges.find(std::make_pair(index[i + 1], index[i]));
            if (iter != edges.end()) {
                opposite[opposite.size() - 1] = iter->second;
                opposite[iter->second] = opposite.size() - 1;
            }
        }
        edges.insert(std::make_pair(std::make_pair(index[index.size() - 1], index[0]), halfedges.size()));
        halfedges.push_back(index[index.size() - 1]);
        facet.push_back(size.size());
        opposite.push_back(UINT_MAX);
        auto iter = edges.find(std::make_pair(index[0], index[index.size() - 1]));
        if (iter != edges.end()) {
            opposite[opposite.size() - 1] = iter->second;
            opposite[iter->second] = opposite.size() - 1;
        }
        unsigned int end = halfedges.size();
        size.push_back(end - begin);
        pred.push_back(end - 1);
        for (int i = begin + 1; i < end; i++)
            pred.push_back(i - 1);
        for (int i = begin; i < end - 1; i++)
            succ.push_back(i + 1);
        succ.push_back(begin);
    }
}