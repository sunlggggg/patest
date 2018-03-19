#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int A[100010];
	int n , m ; 
	scanf("%d%d",&n,&m);
	A[0] = 0 ;
	for(int i = 1 ; i<= n ; i++){
		scanf("%d",&A[i]);
		A[i] += A[i - 1];
	}
	int firstGreat = 100000000;
	for(int i = 1 ;i <= n ; i++){
		//找到第一个a1+a2+ai-1 + ...+aj 大于a1+a2+a2+ai-1 + m 
		int j = upper_bound(A+i,A+n+1,A[i-1]+m) -A ;
		if(A[j - 1] - A[i - 1] == m ){
			firstGreat = m;
			break;
		}else if(j <= n && A[j] - A[i - 1] < firstGreat){
			firstGreat = A[j] - A[i - 1];
		}
	}
	for(int i = 1; i <= n ; i++){
		int j = upper_bound(A+i,A+n+1,A[i-1]+firstGreat) - A;
		if(A[j - 1] -A[i-1] == firstGreat ){
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0 ;
}