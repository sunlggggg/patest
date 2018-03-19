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
#include<sstream>
#include<stack>
#include<algorithm>
#include<queue>
#include<map>
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
vector<pair<int,int>> route;//中间经过的路径
map<int,int> _map; //id和name的映射。。。方便使用邻接矩阵 不然铁定超时
map<int,int>::iterator _mapt;
int n, m ;//n:人数
int id = 0 ;//每个人的序号
int ID(int name ){
	return _map[name];
}
int Name(int ID){
	_mapt = _map.begin();
	while(_mapt!=_map.end()){
		if(_mapt->second == ID)
			return _mapt->first;
		_mapt++;
	}
}
int mstoi(string s){
	stringstream ssm;
	ssm<<s;
	int rt;
	ssm>>rt;
	return rt;
}
void buildMap(){
	memset(Map,MAXDIS,sizeof(Map));//所有的距离为-1
	scanf("%d%d",&n,&m);
	for(int i =0 ; i < m ; i++){
		char t1[6],t2[6];
		scanf("%s%s",&t1,&t2);
		string s1(t1),s2(t2);
		if(_map.count(mstoi(s1)) == 0 ){
			_map[mstoi(s1)] = id++;
		}
		if(_map.count(mstoi(s2)) == 0 ){
			_map[mstoi(s2)] = id++;
		}

		if(s1[0] == '-'){
			gender[ID(mstoi(s1))] = '-';
		}else{
			gender[ID(mstoi(s1))] = '+';
		}
		if(s2[0] == '-'){
			gender[ID(mstoi(s2))] = '-';
		}else{
			gender[ID(mstoi(s2))] = '+';
		}
		Map[ID(mstoi(s1))][ID(mstoi(s2))] = Map[ID(mstoi(s2))][ID(mstoi(s1)) ]  = 1;//fron 到 to 可达
	}
}
void init(){
	memset(dis,MAXDIS,sizeof(dis));//dis
	route.clear();
	(vector<pair<int,int>> (route)).swap(route);//清除内存
	memset(isFind,false,sizeof(isFind));//isFind 
}
bool cmp(pair<int,int> a , pair<int,int> b){
	if(a.first != b.first)
		return a.first < b.first;
	else 
		return a.second<b.second;
}
//深度遍历 目标节点一直不置为true
void deepTravse(int start, int end){
	vector<int> sta; //用来保存前来的路径
	sta.push_back(start);
	isFind[start] = true;
	while(sta.size()){
		int nowStart = sta[sta.size()-1];//栈顶元素
		bool isPop = true ; 
		for(int i = 0; i < n; i++ ){
			if(Map[nowStart][i] == 1 &&!isFind[i]) {
				if(i!=end){//目标节点不加入
					isFind[i] = true;
					sta.push_back(i);
					isPop = false;
					break;
				}
				else if( sta.size() == 3 
					 &&gender[sta[1]]!=gender[sta[2]]
					 &&gender[sta[0]]==gender[sta[1]]) 
				{//abc d
					route.push_back(make_pair(sta[1],sta[2]));
					//不置为true
					break;
				}
			}
		}
		if(isPop){
			sta.pop_back();
		}
	}
}
//输出
void p(){
	sort(route.begin(),route.end(),cmp);
	printf("%d\n",route.size());

	for(int i = 0 ; i < route.size();i++){
		printf("%4d ", abs(Name(route[i].first)));
		printf("%4d\n", abs(Name(route[i].second)));
	}
}
void findRoute(){
	int findCount ;
	scanf("%d",&findCount);
	int from,  to;
	for(int i =0 ; i < findCount  ; i++){
		scanf("%d%d",&from,&to);
		init();//初始化 
		deepTravse(ID(from),ID(to));
		p();
	}
}

int main(){
	buildMap();
	findRoute();
	return 0;
}

/*****
7 8 
-1001 -1002
-1001 -1003
-1002 1004
-1002 1005
1005 1007
1006 1007
-1003 -1006
1004 1007
100
-1001 1007
*****/