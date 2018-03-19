#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<functional>
using namespace std; 
struct A
{
	int p;
	double c;
};
int main(){
	vector<A> v1;
	map<int, double, greater<int> > m;
	map<int, double, greater<int> >::iterator ite;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++){
		A a;
		cin >> a.p >> a.c;
		v1.push_back(a);
	}
	cin >> a;
	for (int i = 0; i < a; i++){
		int p;
		double c;
		cin >> p >> c;
		for (int i = 0; i < v1.size(); i++){
			int np = p+v1[i].p;
			double nc = c*v1[i].c;
			if ((ite = m.find(np)) == m.end())
				m.insert(make_pair(np, nc));
			else {
				ite->second += nc;
			}
		}
	}
	ite = m.begin();
	while (ite != m.end())
	{
		if (fabs(ite->second) < 0.0001){
			ite = m.erase(ite);
		}
		else{
			ite++;
		}
	}
	ite = m.begin();
	cout << m.size();
	while (ite!=m.end())
	{
		printf(" %d %.1lf", ite->first, ite->second);
		ite++;
	}
	cout << endl;
	return 0; 
}

//µÖÏûÎª0 
//¸¡µãÅÐ¶Ï