//
// Created by PantaSun on 2018/11/21.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <vector>
#include <cassert>
#include <iostream>

class DenseGraph {
private:
    int v, e;
    bool directed;
    std::vector<std::vector<bool>> DG;
public:
    DenseGraph(const int n, const bool d);
    ~DenseGraph();
    int V()const ;
    int E()const ;
    void addEdge(const int v1, const int v2);
    bool hasEdge(const int v1, const int v2);
    void show()const;

    class adjIterator{
    private:
        const DenseGraph & dg;
        int v;
        int index;
    public:
        adjIterator(const DenseGraph &g, const int n);
        int begin();
        int next();
        bool end();
    };

};


#endif //GRAPH_DENSEGRAPH_H
