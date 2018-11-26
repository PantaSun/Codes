//
// Created by PantaSun on 2018/11/21.
//

#include "SpareGraph.h"


SpareGraph::SpareGraph(const int n, bool d): v(n), e(0), directed(d) {
    for (int i = 0; i < n; ++i) {
        SG.push_back(std::vector<int>());
    }

}

SpareGraph::~SpareGraph() {

}

int SpareGraph::V() const {
    return v;
}

int SpareGraph::E() const {
    return e;
}

void SpareGraph::addEdge(const int v1, const int v2) {
    assert(v1 >= 0 && v1 < v);
    assert(v2 >= 0 && v2 < v);
    SG[v1].push_back(v2);
    if (v1 != v2 && !directed)
        SG[v2].push_back(v1);
    e++;
}

bool SpareGraph::hasEdge(const int v1, const int v2) const {
    assert(v1 >= 0 && v1 < v);
    assert(v2 >= 0 && v2 < v);
    for (int i = 0; i < SG[v1].size(); ++i) {
        if (SG[v1][i] == v2) return true;
    }
    return false;
}
bool SpareGraph::hasEdge2(const int v1, const int v2) const {
    assert(v1 >= 0 && v1 < v);
    assert(v2 >= 0 && v2 < v);
    if (find(SG[v1].begin(), SG[v1].end(), v2) != SG[v1].end()) return true;
    return false;
}

void SpareGraph::show() const {
    for (int i = 0; i < v; ++i) {
        std::cout << "vertex "<< i << ": ";
        int length = SG[i].size();
        for (int j = 0; j < length ; ++j) {
            std::cout << SG[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

SpareGraph::adjIterator::adjIterator(const SpareGraph &g, const int n):sg(g), v(n), index(0) {

}

int SpareGraph::adjIterator::begin() {
    index = 0;
    if (sg.SG[v].size())
        return sg.SG[v][0];
    return -1;
}

int SpareGraph::adjIterator::next() {
    index++;
    if (!end())
        return sg.SG[v][index];
    return -1;
}

bool SpareGraph::adjIterator::end() {
    return index >= sg.SG[v].size();
}
