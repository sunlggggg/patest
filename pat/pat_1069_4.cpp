//×Ö·û´®¿ªÍ·²åÈë ×Ö·û
#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool isSame(string s){
	char c = s[0];
	for(int i = 1; i < s.size(); i++){
		if(s[i] != c)
			return false;
	}
	return true;
}
int mstoi(string s){
	stringstream ssm ;
	ssm<<s;
	int t;
	ssm>>t;
	return t;
}
string mitos(int b){
	stringstream ssm ;
	ssm<<b;
	string s;
	ssm>>s;
	for(int i = 0 ; i < 4- s.size(); i++){
		s.insert(s.begin(),'0');
	}
	return s;
}
bool cmp(char a, char b){
	return a>b;
}
int main(){
	char t[5];
	scanf("%s",t);
	string s;
	for(int i = 0 ; i < 4- strlen(t); i++){
		s+='0';
	}
	s+=t;
	if(isSame(s)){
		printf("%04d - %04d = 0000",mstoi(s),mstoi(s));
	}else {
		do{
			sort(s.begin(),s.end(),cmp);
			int a = mstoi(s);
			sort(s.begin(),s.end());
			int b = mstoi(s);
			printf("%04d - %04d = %04d\n",a,b,a-b);
			s = mitos(a-b);
		}while(mstoi(s)!=6174);
	}
	return 0;
}
/*

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000

*/
