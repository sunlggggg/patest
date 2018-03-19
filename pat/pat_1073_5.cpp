#include<iostream>
#include<sstream>
#include<string>
using namespace std;
struct A{
	int a,b;
};
A a1(string s){
	A a; 
	for(int i = 1 ; i< s.length();i++ ){
		if(s[i] == '.')
			a.a = i;
		else if(s[i] == '+' || s[i] == '-' ){
			a.b = i;
			return a;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s; 
	if(s[0] == '-')
		cout<<"-";
	A a = a1(s);
	string b  = s.substr(a.b+1, s.length()-a.b);
	stringstream ssm ;
	ssm<<b;
	int i_b;
	ssm>>i_b;	
	int ph = a.b -a.a - 2; //小数点后个数
	if(s[a.b] =='+'){
		if(i_b> ph )	{//补0
			for(int i = 1; i< a.b -1 ;i++){
				if(s[i]!='.')
					cout<<s[i];
			}
			for(int i = 0 ; i< i_b-ph ;i++){
				cout<<"0";
			}
		}
		else { //输出小数点 
			for(int i = 1; i< a.b -1 ;i++){
					if(s[i]!='.')
						cout<<s[i];
					if(i == a.a + i_b && i != a.b -2 ){
						cout<<".";
					}
			}
		}
	}
	else
	{
		
		for(int i = 0 ; i < i_b;i++){
			cout<<"0";
			if(i==0){
				cout<<".";
			}
		}
		for(int i = 1; i< a.b -1 ;i++){
			if(s[i]!='.')
				cout<<s[i];
		}
	}
	return 0 ;
}
/**

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000


*/