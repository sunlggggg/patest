#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct A{
	string name;
	short int h;
	short int m;
	short int s;
};

bool cmpS(const A a,const A b){
	return a.s < b.s;
}
bool cmpH(const A& a, const A& b){
	return a.h < b.h;
}
bool cmpM(const A& a, const A& b){
	return a.m < b.m;
}
int main(){
	ios::sync_with_stdio(false);
	vector<A> v1,v2;
	//int x, y, z;
	//scanf("%d:%d:%d", &x, &y, &z)
	int c;
	cin >> c;
	string name;
	stringstream ss;
	while (c--){
		ss.clear();
		ss.str("");
		A a;
		string  s;
		cin >> a.name >> s;
		ss << s.substr(0,2);
		ss >> a.h;
		ss.clear();
		ss << s.substr(3, 2);
		ss >> a.m;
		ss.clear();
		ss << s.substr(6, 2);
		ss >> a.s;
		v1.push_back(a);
		A a1;
		cin >> s;
		a1.name = a.name;
		ss.clear();
		ss << s.substr(0, 2);
		ss >> a1.h;
		ss.clear();
		ss << s.substr(3, 2);
		ss >> a1.m;
		ss.clear();
		ss << s.substr(6, 2);
		ss >> a1.s;
		v2.push_back(a1);
	}
	stable_sort(v1.begin(), v1.end(), cmpS);
	stable_sort(v1.begin(), v1.end(), cmpM);
	stable_sort(v1.begin(), v1.end(), cmpH);
	stable_sort(v2.begin(), v2.end(), cmpS);
	stable_sort(v2.begin(), v2.end(), cmpM);
	stable_sort(v2.begin(), v2.end(), cmpH);
	cout << v1.front().name << " " << v2.back().name;
	return 0;
}

/*Sample Input :
Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
*/