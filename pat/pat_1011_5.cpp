#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct A{
	char C;
	double V;
};
A MAX(double a, double b, double c){
	A rt;
	if (a >= b && a >= c){
		rt.V = a;
		rt.C = 'W';
	}
	else if (b > a  && b >= c){
		rt.V = b;
		rt.C = 'T';
	}else {
		rt.V = c;
		rt.C = 'L';
	}
	return rt;
}
int main(){
	ios::sync_with_stdio(false);
	double a, b, c;
	double s = 1;
	for (int i = 0; i < 3; i++){
		cin >> a >> b >> c;
		A rt = MAX(a, b, c);
		s *= rt.V;
		cout << rt.C << " ";
	}
	printf("%.2lf" ,(s*0.65 - 1) * 2);
}




//Sample Input
//1.1 2.5 1.7
//1.2 3.0 1.6
//4.1 1.2 1.1
//Sample Output
//T T W 37.98