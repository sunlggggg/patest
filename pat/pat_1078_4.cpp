/**
1078. Hashing (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. 
The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic probing (with positive 
increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the 
smallest prime number which is larger than the size given by the user.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=10^4) and N (<=MSize) which are the user-
defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a 
line are separated by a space.

Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated 
by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input: 
4 4
10 6 4 15    
Sample Output:
0 1 4 -
**/
//Quadratic probing 二次探测
#include<iostream>
#include<cmath>
#define LL long long 
using namespace std;
bool isprime(LL a){
	if(a == 0 || a == 1) return false;
	else if(a == 2) return true;
	else {
		for(int i = 2; i <= sqrt((long double) a )+1; i++){
			if(a%i == 0)
				return false;
		}
		return true;
	}
}
//找到更大的素数
LL findGP(LL a){
	a++;
	while(!isprime(a)){
		a++;
	}
	return a;
}
int main(){
	LL n, m ;
	bool f[10010] = {false};
	scanf("%lld%lld",&n,&m);
	while(!isprime(n)||n < m ){
		n = findGP(n);
	}
	LL num;
	while(m--){
		scanf("%lld",&num);
		LL pos = num%n;
		if(f[pos] == false){
			printf("%lld",pos);
			f[pos] = true;
		}else {
			bool flag = false;
			//二次探测 +1 -1 +4 -4直到失败。。。
			LL off = 1;
			LL sign = 1;
			while(off<n){
				if(f[abs(pos+off*off*sign)%n] == false){
					f[abs(pos+off*off*sign)%n] = true;
					flag = true;
					printf("%lld",abs(pos+off*off*sign)%n);
					break;
				}else{
					//if(sign == -1){
						off++;
					//}
					//sign*=-1;
				}
			}
			if(!flag){
				printf("-");
			}
		}
		if(m!=0)printf(" ");
		else printf("\n");
	}
	return 0;

}