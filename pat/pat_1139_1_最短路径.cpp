/**
1139. First Contact (30)
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
Unlike in nowadays, the way that boys and girls expressing their feelings of love was quite subtle in the early years. When a boy A had a crush on a 
girl B, he would usually not contact her directly in the first place. Instead, he might ask another boy C, one of his close friends, to ask another 
girl D, who was a friend of both B and C, to send a message to B -- quite a long shot, isn't it? Girls would do analogously.

Here given a network of friendship relations, you are supposed to help a boy or a girl to list all their friends who can possibly help them making 
the 
first contact.

Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N (1 < N <= 300) and M, being the total number of 
people and the number of friendship relations, respectively. Then M lines follow, each gives a pair of friends. Here a person is represented by a 4-
digit ID. To tell their genders, we use a negative sign to represent girls.

After the relations, a positive integer K (<= 100) is given, which is the number of queries. Then K lines of queries follow, each gives a pair of 
lovers, separated by a space. It is assumed that the first one is having a crush on the second one.

Output Specification:

For each query, first print in a line the number of different pairs of friends they can find to help them, then in each line print the IDs of a pair 
of friends.

If the lovers A and B are of opposite genders, you must first print the friend of A who is of the same gender of A, then the friend of B, who is of 
the
same gender of B. If they are of the same gender, then both friends must be in the same gender as theirs. It is guaranteed that each person has only 
one gender.

The friends must be printed in non-decreasing order of the first IDs, and for the same first ones, in increasing order of the seconds ones.

Sample Input:
10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001

1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003

5
1001 -2001
-2003 1001
1005 -2001
-2002 -2004
1111 -2003
Sample Output:
4
1002 2004
1003 2002
1003 2003
1004 2002
4
2001 1002
2001 1003
2002 1003
2002 1004
0
1
2003 2001
0
**/

#include<iostream>
#include<cstring>
#include<vector>
#include<Map>
#define MAXDIS 1000000
#define MAXSIZE 310
using namespace std;
//1:构建图
//2:找到长度为3的路径
//3:节点信息保存男女   
//4:需要保存路径
//5:使用floyd 
char gender[MAXSIZE];//保存性别
int dis[MAXSIZE]; //起始节点到该节点的距离
bool isFind[MAXSIZE];//是否已经访问到了节点
int Map[MAXSIZE][MAXSIZE];//有向图
vector<vector<int>> pre;//每个节点的前导节点
map<int,int> _map;
int n, m ;
int id = 0 ;
int ID(int name ){
	return _map[name];
}
int Name(int ID){
	return _map.find(ID)->first;
}
void buildMap(){
	memset(Map,MAXDIS,sizeof(Map));//所有的距离为-1
	scanf("%d%d",&n,&m);
	int from,  to;
	for(int i =0 ; i < m ; i++){
		scanf("%d%d",&from,&to);
		if(from<0){
			gender[abs(from)] = '-';
		}else{
			gender[from] = '+';
		}
		if(to<0){
			gender[abs(to)] = '-';
		}else{
			gender[to] = '+';
		}
		if(_map.count(from) == 0 ){
			_map[from] = id++;
		}
		if(_map.count(to) == 0 ){
			_map[to] = id++;
		}
		Map[ID(from)][ID(to)] = 1;//fron 到 to 可达
	}
}
void init(){
	memset(dis,MAXDIS,sizeof(dis));//dis
	for(int i = 0 ; i < MAXSIZE; i++){
		vector<int> v;
		pre.push_back(v);
	}
	//memset(pre,0,sizeof(pre));//pre
	memset(isFind,false,sizeof(isFind));//isFind 
}
//1001 -2001
int dijkstra(int start,int end){
	dis[start] = 0;
	//找到最近可达节点
	for(int i=0; i < id; i++) {//每次找出一个节点 
		int mindist = MAXDIS;
		int min_index = start;  // 第一次找到的就时起点。。。
		for(int j = 0; j<id; ++j){
			if( !isFind[j] && dis[j] < mindist) {
				min_index = j; // u保存当前邻接点中距离最小的点的号码
				mindist = dis[j];
			}
		}
		isFind[min_index] = true;//加入该节点 
		for(int j=0; j < id; j++){
			if((!isFind[j]) && Map[min_index][j]<MAXDIS) //可达
			{
				if(dis[min_index] + Map[min_index][j] < dis[j]) //在通过新加入的u点路径找到离v0点更短的路径
				{
					dis[j] = dis[min_index] + Map[min_index][j]; //更新dist
					pre[j].clear();//删除原先节点
					pre[j].push_back(min_index); //前导节点
				}else if(dis[min_index] + Map[min_index][j] == dis[j]){//保留原先节点
					pre[j].push_back(min_index);//前导节点
				}
			}
		}
	}
	return dis[end];
}
//输出
void p(int from, int to,int dis){
	vector<pair<int,int>> v;
	if(dis == 3 ){//a-b-c-d
		//遍历 pre 
		for(int i = 0 ; i < pre[to].size();i++){
			if(gender[pre[to][i]]!=gender[to]){//abcd    d:to pre[to][i]:c pre[pre[to][i]][k]:b为异性
				for(int k = 0 ; k < pre[pre[to][i]].size();k++){
					if( gender[pre[pre[to][i]][k]]==gender[to]){
						v.push_back(make_pair(pre[pre[to][i]][k],pre[to][i]));
					}
				}
			}
		}
		//输出
		printf("%d\n",v.size());
		for(int i = 0 ; i < v.size();i++){
			if(gender[v[i].first] == '-'){
				printf("-");
			}
			printf("%4d ", Name(v[i].first));
			if(gender[v[i].second] == '-'){
				printf("-");
			}
			printf("%4d\n", Name(v[i].second));
		}
	}
}
//route
void findRoute(){
	int findCount ;
	scanf("%d",&findCount);
	int from,  to;
	for(int i =0 ; i < findCount  ; i++){
		scanf("%d%d",&from,&to);
		init();//初始化 
		int dis = dijkstra(ID(from),ID(to));
		p(ID(from), ID(to),dis);
	}
}
int main(){
	buildMap();
	findRoute();
	return 0;
}

/*****
6 8 
-1001 1002
-1001 1003
1002 -1004
1002 -1005
-1005 1007
-1006 1007
1003 -1006
-1004 1007
100
-1001 1007
*****/