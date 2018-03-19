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
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;
bool arr[10000][10000];
struct node {
	node(int a1,int b1){
		a = a1;
		b = b1 ;
	}
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
map<int,int> _map; //id和name的映射。。。方便使用邻接矩阵 不然铁定超时
map<int,int>::iterator _mapt;
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
int id = 0 ;
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {  //相同性别保存下来
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a))][abs(stoi(b))] = arr[abs(stoi(b))][abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) //ad 
					continue;
                if (arr[v[abs(c)][j]][v[abs(d)][k]] == true){
                    ans.push_back(node(v[abs(c)][j], v[abs(d)][k]));
				}
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
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