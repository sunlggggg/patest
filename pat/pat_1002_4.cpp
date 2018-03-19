#include<iostream>
#include<functional>
#include<list>
#include<map>
#include<cmath>
using namespace std; 
int main(){
	map<int, double,greater<int>> d; // C++ map��key ���� �Զ�������
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
		//c++ iterator���÷�
		//vector <int>::iterator it;       //it�ܶ�дvector<int>��Ԫ��
		//vector <int>::const_iterator it;  //itֻ�ܶ�vector<int>��Ԫ�أ��������޸�vector<int>�е�Ԫ��
		//string::iterator s;               //s���Զ�дstring�����е�Ԫ��
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
		//cout << " " << it->first << " " << it->second; //ʹ��c ��ʽ�����
		it++;
	}
	return 0; 
}