/**
1003. Emergency (25)
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
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some 
roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency 
call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on 
the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the 
cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road
with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that 
there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams 
you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
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
**/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
const int N = 510;
int Map[N][N] = {0}; //0  -  N-1
int n;
int edges;
int teamNum[N]; 
int MaxteamNum[N]; 
const int MAXD = 1000000;
bool Find[N];
int dis[N];
int router[N];  //��̵���ýڵ��·����Ŀ
//�������team��Ŀ
void dijstra(int from){
	memset(Find,0,sizeof(Find));
	memset(MaxteamNum,0,sizeof(MaxteamNum));
	for(int i = 0 ; i < n ; i++ ){
		dis[i] = MAXD;
	}
	dis[from] = 0;
	MaxteamNum[from] = teamNum[from];
	router[from] = 1;
	while(true){
		int _min = MAXD;
		int _minIndex = -1;
		//�ҵ�����ɴ��
		for(int i = 0 ; i < n ; i++ ){
			if(Find[i] == false && dis[i] < _min ){
				_min = dis[i];
				_minIndex = i;
			}
		}
		Find[_minIndex] = true;
		int thisTimeMax = -1;
		if(_minIndex != -1){
			//����dis
			for(int i = 0 ; i < n ; i++ ) {
				if(Find[i] == false &&Map[_minIndex][i] !=0 && dis[_minIndex]+Map[_minIndex][i] < dis[i] ){
					router[i] = router[_minIndex];
					MaxteamNum[i] = MaxteamNum[_minIndex] + teamNum[i]; //���Ȩֵ��
					dis[i] =  dis[_minIndex]+Map[_minIndex][i] ;
				}else if(Find[i] == false && Map[_minIndex][i] !=0 && dis[_minIndex]+Map[_minIndex][i] == dis[i]){//һ������·��
					router[i] += router[_minIndex];
					if(MaxteamNum[_minIndex] + teamNum[i] > MaxteamNum[i]) {//�������Ȩֵ��
						MaxteamNum[i] = MaxteamNum[_minIndex] + teamNum[i];
					}
					dis[i] = dis[_minIndex]+Map[_minIndex][i];
				}
			}
		}else {
			break;
		}
	}
}
//���·����Ŀ ���� ѡ�� ������Ŀ���
int _f,_t;
int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d%d%d%d",&n,&edges,&_f,&_t);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&teamNum[i]);
	}
	int from, to , num;
	for(int i = 0 ; i < edges; i ++){
		scanf("%d%d%d",&from,&to, &num);
		Map[from][to] = Map[to][from] = num;
	}
	dijstra(_f);
	printf("%d %d\n",router[_t],MaxteamNum[_t]);
	return 0;
}
