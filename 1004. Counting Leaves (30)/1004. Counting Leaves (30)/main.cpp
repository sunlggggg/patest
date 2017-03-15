#include<iostream>
#include<cstring>
#include<vector> 
#include<algorithm>
#include<queue>
using namespace std;


/*****************************************************************************
* File Name          : main.cpp
* Author             : Sunlggggg
* Version            : V1.0.1
* Date               : 03/14/2017
* Description        : Main
*******************************************************************************
* Sample Input
2 1
01 1 02
* Sample Output
0 1
*******************************************************************************/

const int N = 110; 
vector<int> G[N];
int leaf[N] = {0};
int max_h = 1; 

int h[N] = { 0 };

void DFS(int root , int h ){
	max_h = max(h,max_h);
	if (G[root].size() == 0 ){
		leaf[h] ++;
		return;
	}
	for (int i = 0; i < G[root].size(); i++){
		DFS(G[root][i], h+1);
	}
}


void BFS(){
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int node = q.front();
		max_h = max(h[node], max_h);
		q.pop();
		if (G[node].size() == 0){
			leaf[h[node]]++;
		}
		for (int i = 0; i < G[node].size(); i ++ ){
			h[G[node][i]] = h[node] + 1;
			q.push(G[node][i]);
		}

	}
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m; 
	int parent, k, child;
	for (int i = 0; i < m; i++){
		cin >> parent >> k;
		for (int j = 0; j < k; j++){
			cin >> child;
			G[parent].push_back(child);
		}
	}
	DFS(1, 1);






	h[1] = 1;  //初始化根节点

	BFS(1, 1);

	for (int i = 1; i <= max_h; i++ ){
		cout << leaf[i];
		if (i != max_h)
			cout << " ";
	}
	return 0;
}