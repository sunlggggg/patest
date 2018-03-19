/**
1076. Forwards on Weibo (30)
时间限制
3000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
**/

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
const int N = 1010;
int Map[N][N] = {0};
int n;
int L;
bool isFind[N] = {0};
int FirstNotFind(){
	for(int i = 1 ; i <= n ; i++){
		if(isFind[i] == false){
			return i;
		}
	}
	return -1;
}
int _count = 0;
//返回L层内的人数
void dfs(int from,int nowL){
	if(nowL > L){
		return;
	}else{
		isFind[from] = 1;
		_count++;
		for(int i = 1; i<= N ; i++){
			if(Map[from][i] == 1 && isFind[i] == false){
				dfs(i,nowL+1);
			}
		}
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
	scanf("%d%d",&n,&L);
	int followsNum ;
	int to;
	for(int i = 1 ; i <= n; i++){
		scanf("%d",&followsNum);
		for(int k = 0 ; k< followsNum ; k++){
			//有向图
			scanf("%d",&to);
			Map[to][i] = 1;
		}
	}
	int tc ;
	scanf("%d",&tc);
	int _t;
	while(tc--){
		memset(isFind,0,sizeof(isFind));
		_count = 0;
		scanf("%d",&_t);
		dfs(_t,0);
		printf("%d\n",_count-1);
	}
	return 0;
}
