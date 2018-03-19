/**
1013. Battle Over Cities (25)
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
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that
city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities
which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 
highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, 
the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers,
which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which 
represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
**/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1010;
int map[N][N];
int mapCopy[N][N];
int cityNum , connectedNum , testC;
void delEdge(int node){
	for(int k = 1 ; k <= cityNum ; k++ ){
		map[node][k] = map[k][node] = 0 ;
	}
}
void restore(int node){
	for(int k = 1 ; k <= cityNum ; k++ ){
		map[node][k] = mapCopy[node][k];
		map[k][node] = mapCopy[k][node];
	}
}
bool isFind[N];
int FirstNotFind(){
	int rt = -1;
	for(int i = 1; i <= cityNum ; i++ ){
		if(isFind[i] == 0){
			rt = i;
			break;
		}
	}
	return rt;
}
void bfs(int s){
	//bfs
	queue<int> q;
	q.push(s);
	isFind[s] = 1;
	while(q.size()){
		int front = q.front();
		for(int i = 1; i <= cityNum ; i++){
			if(isFind[i] == false && map[front][i] == 1){
				isFind[i] = 1;
				q.push(i);
			}
		}
		q.pop();
	}
}

int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d%d%d",&cityNum , &connectedNum, &testC);
	memset(map,0,sizeof(map));//初始化
	int f, t;
	for(int i = 0 ; i < connectedNum; i ++){
		scanf("%d%d",&f,&t);
		map[f][t] = map[t][f] = 1;//无向图
		mapCopy[f][t] = mapCopy[t][f] = 1;
	}
	int delNode ;
	for(int i = 0 ; i < testC ; i++) {
		memset(isFind,0,sizeof(isFind));
		scanf("%d",&delNode);//删除的节点
		delEdge(delNode);
		isFind[delNode] = 1;
		int c = 0;
		int fnf ;
		while((fnf=FirstNotFind())!=-1){
			c++;
			bfs(fnf);
		}
		if(c != 0){
			printf("%d\n",c-1);
		}
		restore(delNode);
	}
	return 0;
}