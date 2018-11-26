//
// Created by PantaSun on 2018/11/21.
//


#include "DenseGraph.h"

DenseGraph::DenseGraph(const int n, const bool d): v(n), e(0), directed(d) {
    for (int i = 0; i < n ; ++i) {
       DG.push_back(std::vector<bool> (n, false));
    }
}

DenseGraph::~DenseGraph() {

}

int DenseGraph::V() const {
    return v;
}

int DenseGraph::E() const {
    return e;
}

void DenseGraph::addEdge(const int v1, const int v2) {
    assert(v1 >= 0 && v1 < v);
    assert(v2 >= 0 && v2 < v);
    if (hasEdge(v1, v2))
        return;
    DG[v1][v2] = true;
    if (!directed)
        DG[v2][v1] = true;
    e++;
}

bool DenseGraph::hasEdge(const int v1, const int v2) {
    assert(v1 >= 0 && v1 < v);
    assert(v2 >= 0 && v2 < v);
    return DG[v1][v2];
}

void DenseGraph::show() const {
    for (int i = 0; i < v ; ++i) {
        for (int j = 0; j < v; ++j) {
            std::cout << DG[i][j] << "\t";
        }
        std::cout << std::endl;
    }

}


DenseGraph::adjIterator::adjIterator(const DenseGraph &g, const int n):dg(g), v(n), index(-1) {

}

int DenseGraph::adjIterator::begin(){
    index = -1;
    return next();
}

int DenseGraph::adjIterator::next(){
    index++;
    for (; index < dg.V(); index++) {
        if (dg.DG[v][index]) return index;
    }
    return -1;
}

bool DenseGraph::adjIterator::end(){
    return index >= dg.V();
}
