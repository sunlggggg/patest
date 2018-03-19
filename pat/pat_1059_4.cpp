/**
1059. Prime Factors (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HE, Qinming
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
**/

#include<iostream>
#include<map>
#include<cmath>
#define LL long long 
using namespace std;
bool isprime(LL a){
	if(a == 0||a == 1) return false;
	else if(a == 2) return true;
	else {
		for(int i =2; i <= sqrt((long double) a);i++){
			if(a%i== 0) return false;
		}
		return true;
	}
}
//因式分解
int main(){
	LL n;
	map<LL,LL> v;
	map<LL,LL>::iterator vt;
	scanf("%lld",&n);
	LL t = n ;
	if(t==1){
		v[t] = 1;
	}
	while(t>1){
		for(int i = 2; i <= t; i++){//改成n就运行超时了
			while(isprime(i) && t%i == 0 ){
				if(v.count(i) == 1){
					v[i]++;
				}else {
					v[i] = 1;
				}
				t/=i;
			}
		}
	}
	printf("%lld=",n);
	vt = v.begin();
	while(vt!=v.end()){
		if(vt->second != 1)
			printf("%lld^%lld",vt->first,vt->second);
		else 
			printf("%lld",vt->first);
		vt++;
		if(vt!=v.end())
			printf("*");

	}
	printf("\n");
	return 0;
}