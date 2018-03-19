#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string ss[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
	string s;
	
	cin >>s;
	int sum = 0 ;
	for(int i = 0 ; i< s.length();i++){
		sum+=s[i] - '0';
	}
	stringstream ssm;
	ssm<<sum;
	ssm>>s;
	ssm<<s;
	for(int i = 0 ; i < s.length();i++){
		cout<<ss[s[i]-'0'];
		if(i!=s.length()-1){
			cout<<" ";
		}
	}
	return 0;
}