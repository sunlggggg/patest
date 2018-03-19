#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(){
	string a, b;
	cin>>b>>a; 
	set<char> s;
	set<char> notFind;
	for(int i = 0 ; i < a.size(); i++ ){
		if(a[i] >= 'a' && a[i] <= 'z') 
			a[i] = toupper(a[i]);
		s.insert(a[i]);
	}
	for(int i = 0 ; i < b.size(); i++ ){
		if(b[i] >= 'a' && b[i] <= 'z') 
			b[i] = toupper(b[i]);
		if(s.count(b[i]) == 0 && notFind.count(b[i]) == 0) {
			notFind.insert(b[i]);
			printf("%c",b[i]);
		}
	}
	return 0 ; 
}
