/**
1136. A Delayed Palindrome (20)
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
Consider a positive integer N written in standard notation with k+1 digits ai as ak...a1a0 with 0 <= ai < 10 for all i and ak > 0. Then N is palindromic if and only if ai = ak-i for all i. Zero is written 0 and is also palindromic by definition.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number)

Given any positive integer, you are supposed to find its paired palindromic number.

Input Specification:

Each input file contains one test case which gives a positive integer no more than 1000 digits.

Output Specification:

For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:

A + B = C
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line "C is a palindromic number."; or if a palindromic number cannot be found in 10 iterations, print "Not found in 10 iterations." instead.

Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
**/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int mtl(char c){
	return c - '0';
}
string madd(string s , string t){
	int Q = 0;
	for(int i = t.size()-1; i>=0; i -- ){
		if(mtl(s[i]) + mtl(t[i]) + Q >= 10){
			s[i] = ((char)((mtl(s[i]) + mtl(t[i])) + Q - 10 ) +'0');
			Q = 1;
		}else {
			s[i] = ((char)((mtl(s[i]) + mtl(t[i])) + Q  ) +'0');
			Q = 0;
		}
	}
	if(Q){
		s.insert(s.begin(),'1');
	}
	return s;
}
bool isP(string s){
	for(int i = 0 ; i< s.size()/2 ; i++){
		if(s[i]!= s[s.size()-1 - i ] )
			return false;
	}
	return true;
}
int main(){
	char t[1010];
	scanf("%s",&t);
	string s(t);
	int c = 0 ;
	do{
		if(isP(s)){
			printf("%s is a palindromic number.\n",s.c_str());
			break;
		}
		string t = s;
		string ttt = s;
		reverse(t.begin(),t.end());
		s = madd(s,t);
		
		printf("%s + %s = %s\n",ttt.c_str(),t.c_str(),s.c_str());
	}while((++c)<10);
	if(c == 10){
		printf("Not found in 10 iterations.\n");
	}
	return 0;
}