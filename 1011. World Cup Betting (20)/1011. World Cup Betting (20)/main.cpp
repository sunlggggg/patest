#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	double result = 0.65;
	for (int i = 0; i < 3; i++){
		double a1, a2, a3; 
		cin >> a1 >> a2 >> a3;
		double maxL = max(max(a1, a2), max(a2, a3));
		result *= maxL;
		if (maxL == a1){
			cout << "W ";
		}
		else if (maxL == a2){
			cout << "T ";
		}
		else
			cout << "L ";
	}
	printf("%.2f", (result - 1) * 2);
	return 0; 
}