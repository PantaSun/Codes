//
// Created by PantaSun on 2018/11/22.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <cassert>
template <typename Graph>
class Component {
private:
    const Graph &graph;
    int ccount;
    bool *visited;
    int *id;

    void dfs(const int v){
        visited[v] = true;
        id[v] = ccount;  // 属于同一个连通量的结点的id值为同一个ccount值
        typename Graph::adjIterator adj(graph, v);
        for (int i = adj.begin(); !adj.end() ; i = adj.next()) {
            if(!visited[i])
                dfs(i);
        }
    }
public:
    Component(const Graph &g):graph(g), ccount(0),
                              visited(new bool[g.V()]),
                              id(new int[g.V()]){
        int v = g.V();
        for (int i = 0; i < v; ++i) {
            visited[i] = false;     // false表示未被访问过
            id[i] = -1;             // 用来记录每个结点所属的连通量
        }

        for (int j = 0; j <v ; ++j) {
            if (!visited[j]){
                dfs(j);
                ccount++;
            }

        }
    }

    int getComponent() {
        return ccount;
    }

    ~Component(){
        delete [] visited;
    }

    bool isConnected(const int v, const int w){
        assert(v >=0 && v < graph.V());
        assert(w >=0 && w < graph.V());
        return id[v] == id[w];
    }
};



#endif //GRAPH_COMPONENT_H
