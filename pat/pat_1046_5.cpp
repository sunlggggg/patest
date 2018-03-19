#include<iostream>
#include<cmath>
using namespace std;
int m, total;
int dis[100001];
int dist[100001];
int main(){
	cin >> m; 
	total = 0;
	int pre = 0;
	dist[0] = 0;
	for (int i = 0; i < m; i++){
		cin >> dis[i];
		dist[i+1] = dis[i] + pre;
		pre = dist[i + 1];
		total += dis[i];
	}
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		if (s>e){//±£Ö¤ e>s
			int tmp = s;
			s = e; 
			e = tmp;
		}
		int s1 = dist[e-1] - dist[s-1];
		cout <<( (total - s1 > s1 )? s1 : (total - s1)) << endl;
	}

	return 0; 
}