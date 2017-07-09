#include<iostream>
#include<queue>
#include<string.h>
#include<memory>
using namespace std;
#define INF 10 
int  N, M, K;
bool *visited;
int ** map;
int startCity;
queue<int> cityQ;
int roadBybfs(int removeCity);
int main(){
	ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	visited = new bool[N];
	memset(visited, false, N);
	map = new int *[N];
	for (int i = 0; i < N; i++){
		map[i] = new int[N];
		for (int j = 0; j < N; j++ ){
			map[i][j] = INF;
		}
		//memset(map[i], 0 , N*sizeof(int));
	}

	
	for (int i = 0; i < M; i++){
		int city1, city2;
		cin >> city1 >> city2;
		map[city1 - 1 ][city2 - 1] = 1;
		map[city2 - 1 ][city1 - 1] = 1; 
	}
	while (K--)
	{
		int cityRemove;

		cin >> cityRemove;

		cout << roadBybfs(cityRemove - 1) << endl;
	}
	return 0; 
}

int roadBybfs(int removeCity){
	int startCity = (removeCity + 1)%N;
	visited[removeCity] = true;
	int connectedComponent = 1;
	while (true){
		visited[startCity] = true;
		int isFinishedTreverse = 0;
		for (int i = 0; i < N; i++){
			if (map[startCity][i] == 1 && visited[i] == false){
				visited[i] = true;
				cityQ.push(i);
			}
		}
		if (cityQ.size() > 0){
			startCity = cityQ.front();
			cityQ.pop();
			//if lack "continue", the function will return
			continue;
		}
		else {
			for (int i = 0; i < N; i++){
				if (visited[i] == false){
					startCity = i; 
					isFinishedTreverse = 1;
					connectedComponent++;
					break;
				}
			}
		}
		if (isFinishedTreverse == 0)
			break;
	}
	memset(visited, false, N);
	return connectedComponent - 1 ;
}