#include<iostream>  
#include<stack>  
#include<string.h>  
using namespace std;
#define max 1001  
double arrayA[max];
struct Node{
	Node(int e, double c){
		exp = e;
		coe = c;
	}
	int exp;
	double coe;
};

int main(){
	int cntA, i, exp;
	double coe;
	memset(arrayA, 0, sizeof(arrayA));
	cin >> cntA;
	for (i = 0; i<cntA; i++){
		cin >> exp >> coe;
		arrayA[exp] = coe;
	}
	cin >> cntA;
	for (i = 0; i<cntA; i++){
		cin >> exp >> coe;
		arrayA[exp] += coe;
	}
	int cnt = 0;
	stack<Node> sta;
	for (i = 0; i<max; i++){
		if (arrayA[i] != 0){
			Node n(i, arrayA[i]);
			sta.push(n);
		}
	}
	cout << sta.size();
	if (sta.size() != 0){
		while (!sta.empty()){
			printf(" %d %.1lf", sta.top().exp, sta.top().coe);
			sta.pop();
		}
	}
	cout << endl;
	return 0;
}