/**
1015. Reversible Primes (20)
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
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a 
reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 10^5) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
**/

#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
LL trans(LL a,LL radix){
	//4 100 4%2=0 4/2=2 2%2=0 2/2=1 1%2=1
	LL rt = 0 ;
	stack<LL> s;
	while(a!=0){
		s.push(a%radix);
		a/=radix;
	}
	LL r = 1;
	//111 1*1+ 1*2 + 1*4 = 7 
	while(s.size()){
		rt+=s.top()*r;
		s.pop();
		r*=radix;
	}
	return rt;
}
bool isprime(LL a){
	if(a == 2) return true;
	if(a == 0 || a == 1) return false ;
	bool rt = true;
	for(int i = 2; i<=sqrt((long double)a)+1;i++){
		if(a%i == 0)
			rt = false;
	}
	return rt;
}	
int main(){
	LL c = 0 ;
	while(1){
		scanf("%lld",&c);
		if(c>0){
			LL radix;
			scanf("%lld",&radix);
			if(isprime(c) && isprime(trans(c,radix))){
				printf("Yes\n");
			}else {
				printf("No\n");
			}
		}else break;
	}
	return 0;
}