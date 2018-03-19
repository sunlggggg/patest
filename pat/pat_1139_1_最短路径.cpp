/**
1139. First Contact (30)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
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
//1:����ͼ
//2:�ҵ�����Ϊ3��·��
//3:�ڵ���Ϣ������Ů   
//4:��Ҫ����·��
//5:ʹ��floyd 
char gender[MAXSIZE];//�����Ա�
int dis[MAXSIZE]; //��ʼ�ڵ㵽�ýڵ�ľ���
bool isFind[MAXSIZE];//�Ƿ��Ѿ����ʵ��˽ڵ�
int Map[MAXSIZE][MAXSIZE];//����ͼ
vector<vector<int>> pre;//ÿ���ڵ��ǰ���ڵ�
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
	memset(Map,MAXDIS,sizeof(Map));//���еľ���Ϊ-1
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
		Map[ID(from)][ID(to)] = 1;//fron �� to �ɴ�
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
	//�ҵ�����ɴ�ڵ�
	for(int i=0; i < id; i++) {//ÿ���ҳ�һ���ڵ� 
		int mindist = MAXDIS;
		int min_index = start;  // ��һ���ҵ��ľ�ʱ��㡣����
		for(int j = 0; j<id; ++j){
			if( !isFind[j] && dis[j] < mindist) {
				min_index = j; // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
				mindist = dis[j];
			}
		}
		isFind[min_index] = true;//����ýڵ� 
		for(int j=0; j < id; j++){
			if((!isFind[j]) && Map[min_index][j]<MAXDIS) //�ɴ�
			{
				if(dis[min_index] + Map[min_index][j] < dis[j]) //��ͨ���¼����u��·���ҵ���v0����̵�·��
				{
					dis[j] = dis[min_index] + Map[min_index][j]; //����dist
					pre[j].clear();//ɾ��ԭ�Ƚڵ�
					pre[j].push_back(min_index); //ǰ���ڵ�
				}else if(dis[min_index] + Map[min_index][j] == dis[j]){//����ԭ�Ƚڵ�
					pre[j].push_back(min_index);//ǰ���ڵ�
				}
			}
		}
	}
	return dis[end];
}
//���
void p(int from, int to,int dis){
	vector<pair<int,int>> v;
	if(dis == 3 ){//a-b-c-d
		//���� pre 
		for(int i = 0 ; i < pre[to].size();i++){
			if(gender[pre[to][i]]!=gender[to]){//abcd    d:to pre[to][i]:c pre[pre[to][i]][k]:bΪ����
				for(int k = 0 ; k < pre[pre[to][i]].size();k++){
					if( gender[pre[pre[to][i]][k]]==gender[to]){
						v.push_back(make_pair(pre[pre[to][i]][k],pre[to][i]));
					}
				}
			}
		}
		//���
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
		init();//��ʼ�� 
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