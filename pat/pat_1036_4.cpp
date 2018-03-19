#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct A{
	char G;
	string N;
	string  C;
	int Gra;
};
bool cmpG(const A& a,  const A& b){
	return a.G< b.G;
}
bool cmpGra(const A& a, const A& b){
	return  a.Gra < b.Gra;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<A> v1,v2;
	while (n--){
		A a;
		cin >> a.N >> a.G >> a.C >> a.Gra;
		if (a.G == 'F')
			v1.push_back(a);
		else 
			v2.push_back(a);
	}
	stable_sort(v1.begin(), v1.end(), cmpGra);
	stable_sort(v2.begin(), v2.end(), cmpGra);
	if (v1.size() == 0 ){
		cout << "Absent" << endl;
	}else {
		cout << v1.back().N << " " << v1.back().C <<endl;
	}
	if (v2.size() == 0){
		cout << "Absent" << endl;
	}
	else {
		cout << v2.front().N << " " << v2.front().C  << endl;
	}
	if (v1.size() > 0 && v2.size() > 0){
		cout << abs(v1.back().Gra - v2.front().Gra) << endl;
	}
	else{
		cout << "NA" << endl;
	}
	return 0;
}
