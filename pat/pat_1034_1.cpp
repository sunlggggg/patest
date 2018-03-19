/**
1034. Head of a Gang (30)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is 
related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster 
of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with 
maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the 
number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital 
letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number 
of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names 
of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
**/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
//1:删除边 防止回头
//2:我这样的记录重复边
const int N = 26*26*26+1;
map<int, string> intToString;
map<string, int> stringToInt;
int Map[N][N] = {0};
int n;
int K;
bool isFind[N] = {0};
int totalNodeWei[N] = {0};
int oneCount = 0 ;
int head = -1;
int _maxwei =-1;

int dfs(int start ){
	if(totalNodeWei[start]>_maxwei){
		_maxwei = totalNodeWei[start];
		head = start;
	}
	isFind[start] = 1;
	oneCount ++;
	int allWei = 0;
	for(int i = 0 ; i < n ; i++){
		allWei+=Map[start][i];
		if(isFind[i] == 0 && Map[start][i]!= 0 ){
			allWei += dfs(i);
		}
	}
	return allWei;
}
int personNum = 0;
int add(string str){
	if(stringToInt.find(str)!=stringToInt.end()){
		return stringToInt[str];
	}else {
		stringToInt[str] = personNum;
		intToString[personNum] = str;
		return personNum++;
	}
}
int FirstNotFind(){
	for(int i = 0 ; i< n ; i++){
		if(isFind[i] == false){
			return i;
		}
	}
	return -1;
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
	scanf("%d%d",&n,&K);
	char from[4];
	char to[4];
	int wei;
	for(int i = 0 ; i < n; i++){
		scanf("%s%s%d",&from,&to,&wei);
		string s_from(from);
		string s_to(to);
		int fId = add(s_from);
		int tId = add(s_to);
		totalNodeWei[fId]+= wei;
		totalNodeWei[tId]+= wei;

		Map[fId][tId] += wei;//有向图
		Map[tId][fId] += wei;//有向图
	}
	map<string,int> _map;
	int fnf;
	while((fnf= FirstNotFind())!=-1){
		oneCount = 0 ;	
		head = -1;
		_maxwei = -1;
		int allwei = dfs(fnf);
		if(allwei > 2*K && oneCount > 2){
			_map.insert(make_pair(intToString[head],oneCount));
		}
	}
	printf("%d\n",_map.size());
	if(_map.size()){
		map<string,int>::iterator it;
		for(it = _map.begin(); it!=_map.end(); it++){
			printf("%s %d\n",it->first.c_str(),it->second);
		}
	}
	return 0;
}
