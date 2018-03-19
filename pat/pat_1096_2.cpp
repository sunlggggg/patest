/**
1096. Consecutive Factors (20)
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
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:

Each input file contains one test case, which gives the integer N (1<N<2^31).

Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630
Sample Output:
3
5*6*7
**/
//n不能够被大于sqrt(n)+1整除
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL int
using namespace std;
//连续数列 630=5*6*7
pair<int,int> consercu(LL n , int i){
	LL t = n ; 
	int k = i;
	for(k = i ; k <= n ; k++){
		if(t%k == 0 ){
			t/=k;
		}else{
			break;
		}
	}
	k--;
	return make_pair(i,k);
}
bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second - a.first != b.second - b.first)
		return a.second - a.first > b.second - b.first;
	else return a.first < b.first;
}
int main(){
	LL n;
	pair<int,int> maxLenSen;
	maxLenSen.first = 1;
	maxLenSen.second = 0;
	scanf("%d",&n);
	
	//n:2
	for(int i = 2; i<=sqrt((double)n)+1 ; i++){
		pair<int , int> rt = consercu(n,i);
		if(rt.first <= rt.second ){
			if(rt.second -rt.first > maxLenSen.second -maxLenSen.first)
				maxLenSen = rt;
		}
	}
	if(maxLenSen.second == 0 ){
		maxLenSen.first = n;
		maxLenSen.second = n;
	}
	printf("%d\n",maxLenSen.second - maxLenSen.first+1);
	for(long long i = maxLenSen.first ; i<=maxLenSen.second; i++){//2^31-1 是素数 溢出
		printf("%d",i);
		if(i!=maxLenSen.second){
			printf("*");
		}else 
			printf("\n");
	}
	return 0;
}
