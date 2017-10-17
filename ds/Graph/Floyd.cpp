//
// Created by sunlggggg on 2017/8/18.
//
#include <iostream>
#include <cstring>

using namespace std;
#define MAX_NODE_SIZE 9
#define INF_LENGTH 3000

struct Node {
    Node() {}

    Node(int index) : index(index) {}

    int index; //form 0
};

class Graph {
public:
    int nodes_num;
    int edges_num;
    Node nodes[MAX_NODE_SIZE];
    int edges[MAX_NODE_SIZE][MAX_NODE_SIZE];
public:
    Graph() {}

    void build() {
        fill(edges[0], edges[0] + MAX_NODE_SIZE * MAX_NODE_SIZE, INF_LENGTH);
//        5 6
//        0 1 1
//        0 2 2
//        0 3 1
//        1 2 1
//        2 4 1
//        3 4 1
        cin >> nodes_num >> edges_num;
        for (int i = 0; i < nodes_num; i++) {
            int team_num;
            Node node(i);
            nodes[i] = node;
        }
        for (int i = 0; i < edges_num; i++) {
            int form_node;
            int to_node;
            int length;
            cin >> form_node >> to_node >> length;
            //adjacent matrix
            edges[form_node][to_node] = edges[to_node][form_node] = length;
        }
    }
};

class ShortestPaht {
private:
    Graph graph;
    int PahtMatrix[MAX_NODE_SIZE][MAX_NODE_SIZE];
    int ShortPahtTable[MAX_NODE_SIZE][MAX_NODE_SIZE];
public:
    ShortestPaht() {
        graph.build();
    }
    void Flowyd() {
        //init
        memcpy(graph.edges,PahtMatrix, sizeof(graph.edges));
        for (int i = 0; i <graph.nodes_num ; i++ ){
            int a[3][4] = {0};
            int b[3][4]= {0};
            memcpy(b,a,sizeof(b));

        }
    }

    void PrintRoute(int form_index, int to_index) {

    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

