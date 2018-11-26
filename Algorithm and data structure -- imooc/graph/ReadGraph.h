//
// Created by PantaSun on 2018/11/22.
//

#ifndef GRAPH_READGRAPH_H
#define GRAPH_READGRAPH_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

template <typename G>
class ReadGraph {

public:
    ReadGraph(G &graph, const std::string fileName){
        std::ifstream file(fileName);
        std::string line;
        assert(file.is_open());
        int V,E;
        assert(std::getline(file, line));
        std::stringstream ss(line);
        ss >> V >> E;
        assert(V == graph.V());

        int a, b;

        for (int i = 0; i < E; ++i) {
            assert(std::getline(file, line));
            std::stringstream ss(line);
            ss >> a >> b;
            assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);
            graph.addEdge(a, b);
        }
    }

};




#endif //GRAPH_READGRAPH_H
