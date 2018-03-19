/**
1024. Palindromic Number (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number.
All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is
added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we 
start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 10^10) is the initial numer and K (<= 100) is 
the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number 
of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step 
and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
**/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string madd(string s,string t){
	//使用进位
	//保证s长
	if(s.size()<t.size())
		swap(s,t);
	//补0
	for(int i = 0 ; i< s.size() - t.size() ; i++)
		s.insert(s.begin()+(s.size()-t.size()),'0');
	int Q = 0 ;
	for(int i = t.size()- 1 ; i >= 0 ; i-- ){
		if((s[i] - '0')+(t[i] - '0') +Q >= 10 ){
			s[i]= char('0' + (s[i] - '0') + (t[i] - '0')   +Q - 10);
			Q = 1;
		}else {
			s[i]= char('0' + (s[i] - '0')+ (t[i] - '0')  +Q );
			Q = 0 ;
		}
	}
	if(Q){
		s.insert(s.begin()+(s.size()-t.size()),'1');
	}
	//删除首位的0
	bool f = false;
	while(!f&&s.size()>0){
		if(s[0] == '0')
			s.erase(s.begin());
		else 
			f = true;
	}
	return s;
}
bool ispalindromic(string s){
	//121 
	for(int i = 0 ; i < s.size()/2;i++){
		if(s[i] != s[s.size()-i-1]){
			return false;
			break;
		}
	}
	return true;
}
int main(){
	int n;
	char t[20];
	scanf("%s%d",&t,&n);
	string s(t);
	int c = 0 ;
	do{
		if(ispalindromic(s)||c == n ){
			printf("%s\n%d\n",s.c_str(),c);
			break;
		}else {
			string tmp =s;
			reverse(tmp.begin(),tmp.end());
			s = madd(s,tmp);
		}
	}while(c++<=n);
	return 0 ;
}