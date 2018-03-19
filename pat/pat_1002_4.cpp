#include<iostream>
#include<functional>
#include<list>
#include<map>
#include<cmath>
using namespace std; 
int main(){
	map<int, double,greater<int>> d; // C++ map按key 排序 自定义排序
	map<int, double>::iterator it;
	int n1; 	
	cin >> n1; 
	for (int i = 0; i < n1; i++) {
		int a;
		double b; 
		cin >> a >> b;
		d.insert(make_pair(a,b));
	}
	int n2;
	cin >> n2;
	for (int i = 0; i < n2; i++){
		int a;
		double b;
		cin >> a >> b;
		//c++ iterator的用法
		//vector <int>::iterator it;       //it能读写vector<int>的元素
		//vector <int>::const_iterator it;  //it只能读vector<int>的元素，不可以修改vector<int>中的元素
		//string::iterator s;               //s可以读写string对象中的元素
		//string::const_iterator s;
		if ((it = d.find(a)) != d.end()){
			it->second += b;
		}
		else {
			d.insert(make_pair(a, b));
		}
	}
	it = d.begin();
	while (it != d.end())
	{
		if (fabs(it->second) < 0.0001)
			it = d.erase(it);
		else
			it++;
	}
	it = d.begin();
	cout << d.size();
	while (it != d.end())
	{
		if (fabs(it->second)>0.0001 )
			printf(" %d %.1lf", it->first, it->second);
		//cout << " " << it->first << " " << it->second; //使用c 格式化输出
		it++;
	}
	return 0; 
}