#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;

int main(){
	string s1,s2;
	set<char> set;
	getline(cin,s1);
	getline(cin,s2);
	for(int i = 0 ; i < s2.size(); i++ ){
		set.insert(s2[i]);
	}
	for(int i = 0 ; i < s1.size(); i++ ){
		if(set.count(s1[i])==0){
			printf("%c",s1[i]);
		}
	}
	return 0;
}