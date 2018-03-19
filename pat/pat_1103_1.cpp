/**
1103. Integer Factorization (30)
时间限制
1200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL

If there is no solution, simple output "Impossible".

Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
**/
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int  n, k , p; 
vector<int> fac,ans,temp;
int mpow(int n, int p ){
	int ans = 1;
	while(p--){
		ans*=n;
	}
	return ans;
}
int maxFacSum = -1;//最大底数之和
void DFS(int index, int nowK, int sum, int facSum){
	if(sum == n && nowK == k ){
		if(facSum>maxFacSum){
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if(sum>n || nowK > k ) {
		return;
	}
	if(index>=1){
		temp.push_back(index); //底数index加入临时序列temp 
		DFS(index, nowK+1,sum+fac[index],facSum+index);//选
		temp.pop_back();
		DFS(index-1, nowK,sum,facSum);//不选
	}
}
int main() {
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d%d%d",&n,&k,&p);
	int i = 0 ;
	int _fac;
	while((_fac=mpow(i++,p))<=n){
		fac.push_back(_fac);
	}
	DFS(fac.size()-1,0,0,0);
	if(maxFacSum == - 1){
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i = 1; i < ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
	return 0;
}