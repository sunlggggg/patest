#include<iostream>
#include<math.h>
using namespace std;

/* 
 * input:
 * 2 1 2.4 0 3.2
 * 2 2 1.5 1 0.5
 *
 * output:
 * 3 3 3.6 2 6.0 1 1.6
 */
#define EPSION  0.000001
#define MAX  2000

 
int main(){
	ios::sync_with_stdio(false);
	int n,ex;
	float res[MAX] = { 0 };
	float poly1[MAX / 2 + 1]  { 0 };
	float poly2[MAX / 2 + 1] = { 0 };
	float co;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ex >> co;
		poly1[ex] = co;
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		
		cin >> ex >> co;
		poly2[ex] = co;
	}
	for (int i = 0; i <= MAX / 2 + 1; i++){
		for (int j = 0; j <= MAX / 2 + 1; j++){
			res[i + j] += poly1[i] * poly2[j];
		}
	}
	int count = 0;
	for (int i = 0; i < MAX; i++){
		if (fabs(res[i]) > EPSION)
			count++;
	}
	cout << count ;

	for (int i = MAX -1 ; i >= 0 ; i--){
		if (fabs(res[i]) > EPSION)
			printf(" %d %.1lf", i, res[i]);
	}
 	return 0;
}