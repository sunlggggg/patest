/**
1132. Cut Integer (20)
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
Cutting an integer means to cut a K digits long integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, 
we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 x 334) = 3. Given an integer Z, you
are supposed to test if it is such an integer.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 20). Then N lines follow, each gives an integer Z 
(10<=Z<=231). It is guaranteed that the number of digits of Z is an even number.

Output Specification:

For each case, print a single line "Yes" if it is such a number, or "No" if not.

Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No
**/


#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
#define LL long long
int n ; 
string mitos(LL i ){
	stringstream ssm;
	ssm<<i;
	string s;
	ssm>>s;
	return s;
}
LL mstoi(string s){
	stringstream ssm;
	ssm<<s;
	LL i;
	ssm>>i;
	return i;
}
bool judge(LL num) {
	string snum = mitos(num);
	int len = snum.size()/2;
	int a = mstoi(snum.substr(0,len));
	int b = mstoi(snum.substr(len,len*2));
	if(a == 0 || b == 0){
		return false;
	}
	else if(num%(a*b)==0)
		return true;
	else 
		return false;
}
int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d", &n);
	LL num;
	for(int i = 0 ; i < n ; i++){
		scanf("%lld",&num);
		if(judge(num)){
			printf("Yes\n");
		}else {
			printf("No\n");
		}
	}
	return 0;
}
