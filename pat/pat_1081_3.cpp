/**
1081. Rational Sum (20)
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
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2
b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front 
of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" 
< "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
**/
//负号可以正常读入
#include<iostream>
#define LL long long
using namespace std;
struct A{
	A(){
		fz = 0;
		fm = 1;
	}
	LL fz,fm;
};
A add(A a, A b){
	A rt;
	rt.fz = a.fz*b.fm + a.fm*b.fz;
	rt.fm = a.fm*b.fm;
	while(1){
		bool f = false;
		for(int i = 2;i<= min(rt.fz,rt.fm); i++){
			if(rt.fz % i == 0 && rt.fm%i==0){
				rt.fz/=i;
				rt.fm/=i;
				f = true;
			}
		}
		if(!f)
			break;
	}
	return rt;
}
int main(){
	int n ;
	scanf("%d",&n);
	A a;
	a.fm = 1;
	for(int i = 0 ; i < n; i++) {
		A b ;
		scanf("%lld/%lld",&b.fz,&b.fm);
		a = add(a,b);
	}
	if(a.fz == 0 ){
		printf("0");
	}else if(a.fm == 1){
		printf("%lld",a.fz);
	}else if(a.fz > a.fm ){
		printf("%lld ",a.fz/a.fm);
		printf("%lld/%lld",a.fz%a.fm,a.fm);
	}else {
		printf("%lld/%lld",a.fz,a.fm);
	}
	return 0 ;
}