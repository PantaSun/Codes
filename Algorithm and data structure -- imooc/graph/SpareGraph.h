//
// Created by PantaSun on 2018/11/21.
//

#ifndef GRAPH_SPAREGRAPH_H
#define GRAPH_SPAREGRAPH_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
class SpareGraph {
private:
    std::vector<std::vector<int>> SG;
    bool directed;
    int v;
    int e;
public:
    SpareGraph(const int n, bool d);
    ~SpareGraph();
    int V()const;
    int E()const;

    void addEdge(const int v1, const int v2);
    bool hasEdge(const int v1, const int v2) const;
    bool hasEdge2(const int v1, const int v2)const;
    void show()const;

    class adjIterator{
    private:
        const SpareGraph &sg;
        int v;
        int index;
    public:
        adjIterator(const SpareGraph& g, const int n);
        int begin();
        int next();
        bool end();
    };
};


#endif //GRAPH_SPAREGRAPH_H
