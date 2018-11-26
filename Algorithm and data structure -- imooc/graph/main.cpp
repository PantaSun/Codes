#include <iostream>
using namespace std;
#include "SpareGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
int main() {

//    union Test{
//        char add;
//        int data;
//    } test;
//    test.data = 0x12345678;
//    if (test.add == 0x12)
//        cout << "大端法" << endl;
//    else if(test.add == 0x78)
//        cout << "小端法"  <<  endl;
    std::cout << "Hello, World!" << std::endl;
    int n1 = 13;
    int n2 = 7;
    string fileName2 = "testG2.txt";
    string fileName1 = "testG1.txt";
    SpareGraph sg(n2, false);
    DenseGraph dg(n2, false);
    ReadGraph<SpareGraph> rsg(sg, fileName2);
    ReadGraph<DenseGraph> rdg(dg, fileName2);
    cout << "SpareGraph: " << endl;
    sg.show();
    cout << "DenseGraph: " << endl;
    dg.show();

    Component<SpareGraph> csg(sg);
    Component<DenseGraph> dsg(dg);
    cout << "There are/is " << csg.getComponent() << " components in the " << fileName2 << endl;
    cout << "There are/is " << dsg.getComponent() << " components in the " << fileName2 << endl;

    Path<SpareGraph> psg(sg, 0);
    cout << "DFS: ";
    psg.showPath(4);

    ShortestPath<SpareGraph> ssg(sg, 0);
    cout << "BFS("<<ssg.getPatlLength(4) <<"): ";
    ssg.showPath(4);

//
//    int v1, v2;
//    char output[64];
//    cout << "请输入大小在 [0-" << n1 << ") 之间的两个数：" << endl;
//    for (int i = 0; i < n1; ++i) {
//        cin >> v1 >> v2;
//        assert(v1 >= 0 && v1 < n1);
//        assert(v2 >= 0 && v2 < n1);
//        if (csg.isConnected(v1, v2))
//            sprintf(output, "%d, %d is connected.", v1, v2);
//        else
//            sprintf(output, "%d, %d is not connected.",v1, v2);
//
//        cout << output << endl;
//    }

//    cout << "SpareGraph: " << endl;
//    for (int j = 0; j < n; ++j) {
//        cout << j << ": ";
//        SpareGraph::adjIterator adj(sg, j);
//        for (int w = adj.begin(); !adj.end() ; w = adj.next()) {
//            cout << w << " ";
//        }
//        cout << endl;
//    }
//
    cout << "DenseGraph: " << endl;
    for (int j = 0; j < n2; ++j) {
        cout << j << ": ";
        DenseGraph::adjIterator adj(dg, j);
        for (int w = adj.begin(); !adj.end() ; w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;

    }

    return 0;
}