#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define INF 0x3f3f3f3f


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

output:
2 4


5 6 1 2 
1 0 0 0 
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


int teamNumbers[1000];
int map[1000][1000];
int dist[1000];           // the distance from startVertex to EndVertex 
int maxTeams[1000];       //the max teams arrive the 'i'
int isFind[1000];       //the node wh 'out'
int vertexPath[1000];   // the 'i' ways to arrive 

void Dijkstra(int start , int numVertexs ){
	dist[start] = 0; // the distance to vertex 'start' is 0 
	vertexPath[start] = 1;  //to vertex 'start' is 0 
	maxTeams[start] = teamNumbers[start];
	queue<int> q; 
	q.push(start);
	while (!q.empty()){
		int vertex = q.front();
		q.pop();
		for (int i = 0; i < numVertexs; i++){
			if (map[vertex][i] != INF && isFind[i] == 0 ){
				if (dist[vertex] + map[vertex][i] < dist[i]){
					dist[i] = dist[vertex] + map[vertex][i];
					vertexPath[i] = vertexPath[vertex];
					maxTeams[i] = maxTeams[vertex] + teamNumbers[i]; 
				}
				else if (dist[vertex] + map[vertex][i] == dist[i]){
					vertexPath[i] = vertexPath[vertex] + vertexPath[i];
					if (maxTeams[vertex] + teamNumbers[i] > maxTeams[i]){
						maxTeams[i] = maxTeams[vertex] + teamNumbers[i];
					}
				}
				q.push(i);
			}
		}
		isFind[vertex] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
		cin >> teamNumbers[i];
	memset(dist, INF, sizeof(dist));
	memset(map, INF, sizeof(map));
	memset(vertexPath, 1, sizeof(vertexPath));
	memset(isFind, 0, sizeof(isFind));
	memset(maxTeams, 0,sizeof(maxTeams));
	for (int i = 0; i < M ; i ++ ){
		int c1, c2, L;
		cin >> c1 >> c2 >> L;
		map[c1][c2] = L;
	}
	Dijkstra(C1,N);
	cout << vertexPath[C2] <<" "<< maxTeams[C2];
	return 0;
}
