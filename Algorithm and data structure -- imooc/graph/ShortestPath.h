//
// Created by PantaSun on 2018/11/24.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include <queue>
#include <cassert>
#include <stack>
#include <iostream>

template <typename Graph>
class ShortestPath {
private:
    const Graph & graph;
    int s;
    bool *visited;
    int *from;
    int *pathLenth;
public:
    ShortestPath(const Graph &g, const int v):graph(g), s(v),
                                              visited(new bool[g.V()]),
                                              from(new int[g.V()]),
                                              pathLenth(new int[g.V()]) {
        int gSzie = g.V();
        for (int i = 0; i < gSzie; ++i) {
            visited[i] = false;
            from[i] = -1;
            pathLenth[i] = -1;
        }
        assert(v >= 0 && v < gSzie);
        std::queue<int> q;
        q.push(v);
        visited[v] = true;
        pathLenth[v] = 0;

        while (!q.empty()){
            int temp = q.front();
            q.pop();
            typename Graph::adjIterator adj(g, temp);
            for (int i = adj.begin(); !adj.end() ; i = adj.next()) {
                if (!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    from[i] = temp;
                    pathLenth[i] = pathLenth[temp] + 1;
                }
            }
        }


    }
    ~ShortestPath(){
        delete [] visited;
        delete [] from;
        delete [] pathLenth;
    }
    bool hasPath(const int w){
        assert(w >= 0 && w < graph.V());
        return visited[w];
    }

    void path(const int w, std::vector<int> &vec){
        assert(w >= 0 && w < graph.V());
        std::stack<int> ss;
        int p = w;
        while (p != -1){
            ss.push(p);
            p = from[p];
        }
        vec.clear();
        while (!ss.empty()){
            int temp = ss.top();
            vec.push_back(ss.top());
            ss.pop();
        }
    }
    void showPath(const int w){
        assert(w >= 0 && w < graph.V());
        std::vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size() ; ++i) {
            std::cout << vec[i];
            if ( i == vec.size()-1)
                std::cout << std::endl;
            else
                std::cout << " -> ";
        }
    }

    int getPatlLength(const int w){
        assert(w >= 0 && w < graph.V());
        return pathLenth[w];

    }

};


#endif //GRAPH_SHORTESTPATH_H
