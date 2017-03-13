#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define INF 0x3f3f3f3f



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

case 1: cout << vertexPath[C2] << " " << maxTeams[C2];
	    C1 -> C2 or C2 - > C1 eew don't konw !
case 2: if use the queue, maybe  the repetitive vertex will be added into the queue 
        Vertex1 -> Vertex2 and Vertex3 but Vertex2 -> Vertex3 so the Vertex3 will be repetitive 


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

const int MAXV = 510;
int teamNumbers[MAXV];
int map[MAXV][MAXV];
int dist[MAXV];           // the distance from startVertex to EndVertex 
int maxTeams[MAXV];       //the max teams arrive the 'i'
int isFind[MAXV];       //the node wh 'out'
int vertexPath[MAXV];   // the 'i' ways to arrive 

void Dijkstra(int start , int numVertexs ){ 
	dist[start] = 0; // the distance to vertex 'start' is 0 
	vertexPath[start] = 1;  //to vertex 'start' is 0 
	maxTeams[start] = teamNumbers[start]; 
	for (int j = 0; j < numVertexs; j++ ){     
		int  vertex = -1, MIN = INF;
		for (int i = 0; i < numVertexs; i++){
			if (isFind[i] == 0 && dist[i] < MIN){
				vertex = i;
				MIN = dist[i];
			}
		}
		if (vertex == -1)
			return;
		isFind[vertex] = 1;
		for (int v = 0; v < numVertexs; v++){
			if (map[vertex][v] != INF && isFind[v] == 0){
				if (dist[vertex] + map[vertex][v] < dist[v]){
					dist[v] = dist[vertex] + map[vertex][v];
					vertexPath[v] = vertexPath[vertex];
					maxTeams[v] = maxTeams[vertex] + teamNumbers[v];
				}
				else if (dist[vertex] + map[vertex][v] == dist[v]){
					vertexPath[v] = vertexPath[vertex] + vertexPath[v];
					if (maxTeams[vertex] + teamNumbers[v] > maxTeams[v]){
						maxTeams[v] = maxTeams[vertex] + teamNumbers[v];
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
		cin >> teamNumbers[i];
	fill(dist, dist + MAXV,INF);
	fill(map[0], map[0] + MAXV * MAXV , INF);
	//memset(dist, INF, sizeof(dist));
	//memset(map, INF, sizeof(map));
	memset(vertexPath, 1, sizeof(vertexPath));
	memset(isFind, 0, sizeof(isFind));
	memset(maxTeams, 0,sizeof(maxTeams));
	for (int i = 0; i < M ; i ++ ){
		int c1, c2, L;
		cin >> c1 >> c2 >> L;
		map[c1][c2] = map[c2][c1]  = L; 
	}
	Dijkstra(C1,N);
	cout << vertexPath[C2] <<" "<< maxTeams[C2];
	return 0;
}
