//
// Created by PantaSun on 2018/11/24.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <vector>
#include <stack>
#include <iostream>

template <typename Graph>
class Path {
private:
    const Graph & graph;
    int s;
    int     *from;
    bool    *visited;

    void dfs(const int v){
        visited[v] = true;
        typename Graph::adjIterator adj(graph, v);
        for (int j = adj.begin(); !adj.end() ; j = adj.next()) {
            if(!visited[j]){
                dfs(j);
                from[j] = v;
            }
        }
    }


public:
    Path(const Graph & g, const int v): graph(g), s(v),
                                        from(new int[g.V()]),
                                        visited(new bool[g.V()])
    {
        int gSize = g.V();
        for (int i = 0; i < gSize; ++i) {
            from[i] = -1;       // 表示节点i是从哪个节点遍历过来的，即路径，-1表示源节点
            visited[i] = false; // 表示i节点是否遍历过，false表示未遍历过
        }

        dfs(v);

    }
    ~Path(){
        delete [] from;
        delete [] visited;
    }
    bool hasPath(const int w){
        return visited[w];
    }

    void path(const int w, std::vector<int> &vec){
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

};


#endif //GRAPH_PATH_H
