//
// Created by 孙鹏达 on 2018/11/26.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

template <typename Weight>
class Edge {
private:
    int v1;
    int v2;
    Weight weight;
public:
    Edge(){}
    Edge(const int a, const int b, Weight w): v1(a), v2(b), weight(w){}
    ~Edge(){}
    int v(){
        return v1;
    }
    int w(){
        return v2;
    }

    Weight wt(){
        return weight;
    }

};


#endif //GRAPH_EDGE_H
