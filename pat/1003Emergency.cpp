#include <iostream>

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
1003. Emergency (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue

As an emergency rescue team leader of a city, you are given a special map of your country.
The map shows several scattered cities connected by some roads. Amount of rescue teams in
each city and the length of each road between any pair of cities are marked on the map.
When there is an emergency call to you from some other city, your job is to lead your men
to the place as quickly as possible【1】, and at the mean time, call up as many hands 【2】on the
way as possible.

Input: Each input c contains one test case. For each test case, the first line contains 4
positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1),
M - the number of roads, C1 and C2 - the cities that you are currently in and that you must
save, respectively. The next line contains N integers, where the i-th integer is the number of
rescue teams in the i-th city. Then M lines follow, each describes a road with three integers
c1, c2 and L, which are the pair of cities connected by a road and the length of that road,
respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output：For each test case, print in one line two numbers: the number of different shortest
paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra
space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
case 1: cout << vertexPath[C2] << " " << maxTeams[C2];
	    C1 -> C2 or C2 - > C1 eew don't konw !
case 2: if use the queue, maybe  the repetitive vertex will be added into the queue
        Vertex1 -> Vertex2 and Vertex3 but Vertex2 -> Vertex3 so the Vertex3 will be repetitive

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define INF_LENGTH  9999
#define MAX_NODE_SIZE 500

struct Node {
    Node() {}

    Node(int index, int team_num) : index(index), team_num(team_num),
                                    is_add(false),
                                    pre_node_num(0),
                                    max_teams_num(0), //至少有本身的数目
                                    shortest_path(INF_LENGTH),
                                    pre_node_index(-1) {}

    int max_teams_num;
    int pre_node_num;
    int index; //form 0
    int team_num; //team_num
    bool is_add;  //是否已经加入最短路径生成树
    int shortest_path; //到达这个点的最短距离
    int pre_node_index; //生成的最短路径的前驱节点
};


struct Map {
    Map() {}

    Map(int nodes_num, int edges_num) :
            nodes_num(nodes_num), edges_num(edges_num) {
        fill(edges[0], edges[0] + MAX_NODE_SIZE * MAX_NODE_SIZE, INF_LENGTH);
    }

    int nodes_num;
    int edges_num;
    Node nodes[MAX_NODE_SIZE];
    int edges[MAX_NODE_SIZE][MAX_NODE_SIZE];
};

class ShortestPath {
private:
    Map map;
    int start_node_index;
    int end_node_index;

//    int _find_node_index(char node_info) {
//        Node *nodes = map.nodes;
//        for (int i = 0; i < map.nodes_num; i++) {
//            if (node_info == map.nodes[i].team_num) {
//                return i;
//            }
//        }
//    }

public:
    void Init() {
        //通过输入   i
        int nodes_num, edges_num;
        cin >> nodes_num >> edges_num;
        cin >> start_node_index >> end_node_index;
        map = Map(nodes_num, edges_num);

        //nodes team_num
        for (int i = 0; i < nodes_num; i++) {
            int team_num;
            cin >> team_num;
            Node node(i, team_num);
            map.nodes[i] = node;
        }
        for (int i = 0; i < edges_num; i++) {
            int form_node;
            int to_node;
            int length;
            cin >> form_node >> to_node >> length;
            //adjacent matrix
            map.edges[form_node][to_node]
                    = map.edges[to_node][form_node]
                    = length;
        }
    }

    void Dijkstra() {
        map.nodes[this->start_node_index].is_add = true;
        map.nodes[this->start_node_index].max_teams_num = map.nodes[this->start_node_index].team_num;
        map.nodes[this->start_node_index].shortest_path = 0;
        //当前出发点的路径数为1 相当于 指向开始节点的路径数
        map.nodes[this->start_node_index].pre_node_num = 1;
        int pre_added_node_index = start_node_index;
        while (true) {
            for (int i = 0; i < map.nodes_num; i++) {
                if (!map.nodes[i].is_add && map.edges[pre_added_node_index][i] != INF_LENGTH) {
                    //<= 节点多 < 节点少
                    //上次加入的节点 到i更近 那么就更新
                    if (map.nodes[pre_added_node_index].shortest_path
                        + map.edges[pre_added_node_index][i] <= map.nodes[i].shortest_path) {



                        //更新路径前驱数目
                        if (map.nodes[pre_added_node_index].shortest_path
                            + map.edges[pre_added_node_index][i] == map.nodes[i].shortest_path) {

                            if (map.nodes[i].team_num + map.nodes[pre_added_node_index].max_teams_num >
                                map.nodes[i].max_teams_num) {
                                //设置前驱下标
                                map.nodes[i].pre_node_index = pre_added_node_index;
                                map.nodes[i].max_teams_num =
                                        map.nodes[pre_added_node_index].max_teams_num + map.nodes[i].team_num;
                            }
                            //并入新的路径
                            map.nodes[i].pre_node_num += map.nodes[pre_added_node_index].pre_node_num;

                        } else {
                            //设置前驱下标
                            map.nodes[i].pre_node_index = pre_added_node_index;
                            //相同的路径数
                            map.nodes[i].pre_node_num = map.nodes[pre_added_node_index].pre_node_num;
                            map.nodes[i].max_teams_num =
                                    map.nodes[pre_added_node_index].max_teams_num + map.nodes[i].team_num;
                        }


                        //放在上面的判断完成以后
                        map.nodes[i].shortest_path = map.nodes[pre_added_node_index].shortest_path
                                                     + map.edges[pre_added_node_index][i];


                    }
                }
            }


            //保证INF_LENGTH足够大
            int min_shortest_path = INF_LENGTH;
            int min_add_index = -1;
            //找到下一个最近的节点
            for (int i = 0; i < map.nodes_num; ++i) {
                if (!map.nodes[i].is_add && map.nodes[i].shortest_path < min_shortest_path) {
                    min_shortest_path = map.nodes[i].shortest_path;
                    min_add_index = i;
                }
            }
            if (min_add_index == -1) {
                return;
            } else {
                map.nodes[min_add_index].is_add = true;
                pre_added_node_index = min_add_index;
            }
        }

    }

    void print() {
        if (map.nodes[end_node_index].pre_node_num != 0)
            cout << map.nodes[end_node_index].pre_node_num << " " << map.nodes[end_node_index].max_teams_num;
        else
            cout << map.nodes[end_node_index].pre_node_num << " " << map.nodes[end_node_index].team_num;
    }
};

int main() {
    ios::sync_with_stdio(false);

    /**
     * fill(dist, dist + MAXV, INF);
     * fill(map[0], map[0] + MAXV * MAXV, INF);
         //memset(dist, INF, sizeof(dist));
         //memset(map, INF, sizeof(map));
     * memset(vertexPath, 1, sizeof(vertexPath));
     * memset(isFind, 0, sizeof(isFind));
     * memset(maxTeams, 0, sizeof(maxTeams));
    */
    ShortestPath shortestPath;
    shortestPath.Init();
    shortestPath.Dijkstra();
    shortestPath.print();
    flush(cout);
    return 0;
}
