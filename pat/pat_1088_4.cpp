/**
1088. Rational Arithmetic (20)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
**/
//使用long long 
//gcd 记住。。。
#include<iostream>
#include<cmath>
#define LL long long
using namespace std;
struct A{
	long long fz;
	long long fm;
};
long long gcd(LL a, LL b ){
	if(a%b==0)return b ;
	else gcd(b,a%b);
}
void yuefen(A &rt){
	LL ys = gcd(abs(rt.fz),rt.fm);
	rt.fz/=ys;
	rt.fm/=ys;
}
void p(A a){
	if(a.fz<0){
		printf("(");
	}
	if(a.fz == 0 ){//0
		printf("0");
	}
	else {//非0
		if(a.fm == 1){// 3/1  3
			printf("%lld", a.fz);
		}
		else if(abs(a.fz) > a.fm ){// 3/2  1 1/2
			printf("%lld %lld/%lld", a.fz/a.fm,abs(a.fz%a.fm),a.fm);
		}else {
			printf("%lld/%lld", a.fz,a.fm);
		}
	}
	if(a.fz<0){
		printf(")");
	}
}
//1/2 + 1/3 = (1*3 + 2*1 )/2*3 = 5/6
A add(A a, A b){  
	A rt;
	rt.fz = a.fz * b.fm + a.fm * b.fz ;
	rt.fm = a.fm * b.fm;
	yuefen(rt);
	return rt;
}
//1/2 * -1/3 
A mul(A a, A b){  
	A rt;
	rt.fz = a.fz * b.fz ;
	rt.fm = a.fm * b.fm;
	yuefen(rt);
	return rt;
}
int main(){
	A a,b;
	scanf("%lld/%lld %lld/%lld",&a.fz , &a.fm , &b.fz , &b.fm);
	yuefen(a);
	yuefen(b);
	//add 1 2/3 + 0 = 1 2/3
	p(a);
	printf(" + ");
	p(b);
	printf(" = ");
	p(add(a,b));
	printf("\n");
	//minus
	p(a);
	printf(" - ");
	p(b);
	printf(" = ");
	b.fz*=-1;//添-
	p(add(a,b));
	printf("\n");
	b.fz*=-1;//消除-
	//mul
	p(a);
	printf(" * ");
	p(b);
	printf(" = ");
	p(mul(a,b));
	printf("\n");
	//div
	p(a);
	printf(" / ");
	p(b);
	printf(" = ");
	if(b.fz == 0 ){
		printf("Inf\n");
	}else{
		if(b.fz<0){
			b.fz *= -1;
			b.fm*=-1;
		}
		int t = b.fz;
		b.fz = b.fm;
		b.fm = t;
		p(mul(a,b));
		printf("\n");
	}
	return 0;
}