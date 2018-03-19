//注意mod 防止溢出  和 不要部分
#include<iostream>
#include<string>
using namespace std;
int main(){
	char t[100010];
	int leftTn[100010];
	int leftPn[100010];
	scanf("%s",t);
	string s(t);
	int pn = 0 , tn = 0 ;
	for(int i = 0 ; i< s.size(); i++){
		if(s[i] =='P'){
			pn++;
		}else if(s[i] == 'T'){
			tn++;
		}else if(s[i] == 'A'){
			leftTn[i] = tn;
			leftPn[i] = pn ;
		}
	}
	int rt = 0;
	for(int	i = 0 ; i< s.size(); i++){
		if(s[i] == 'A'){
			rt =(rt+ leftPn[i]*(tn - leftTn[i])) % 1000000007;//防止溢出
		}
	}
	printf("%d\n",rt);
	return 0 ; 
}	
