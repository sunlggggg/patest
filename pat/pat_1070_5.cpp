//×¢Òâdouble ºÍ int
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct A{
	double pro;
	double cl;
	double dj;
};
bool cmp(A a, A b){
	return a.dj > b.dj;
}
int main(){
	vector<A> v;
	int n ;
	cin >> n ; 
	int amount ;
	cin>>amount;
	for(int i = 0 ; i< n ; i++){
		A a;
		cin >> a.cl ;
		v.push_back(a);
	}
	for(int i = 0 ; i< n ; i++){
		cin >>v[i].pro ;
		v[i].dj =v[i].pro/ v[i].cl;
	}
	sort(v.begin(),v.end(),cmp);
	double profit = 0 ;
	for(int i = 0 ; i< v.size(); i++){
		if(amount>=v[i].cl){
			profit += v[i].pro;
			amount-=v[i].cl;
		}else {
			profit += v[i].dj * amount;
			break;
		}
	}
	printf("%.2f",profit);
	return 0 ;
}
/*

3 200
180 150 100
7.5 7.2 4.5

*/