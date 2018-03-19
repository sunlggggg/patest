#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int A[1010];
	int Out[1010];
	int leftMAX[1010];
	int rightMIN[1010];
	scanf("%d",&n);
	int LM = -1;
	for(int i = 0;i < n ; i++){
		leftMAX[i] = LM;
		scanf("%d",&A[i]);
		if(A[i] > LM){
			LM = A[i];
		}
	}
	int RMIN = 1000000010;
	for(int i = n-1;i >=0  ; i--){
		rightMIN[i] = RMIN;
		if(A[i] < RMIN ){
			RMIN = A[i];
		}
	}
	int c = 0 ;
	for(int i = n-1;i >=0  ; i--){
		if(A[i] <= rightMIN[i]&& A[i] >= leftMAX[i]){
			Out[c++] = A[i];
		}
	}
	sort(Out,Out+c);
	printf("%d\n",c);
	for(int i = 0;i < c ; i++){
		printf("%d",Out[i]);
		if(i!= c- 1)
			printf(" ") ;
	}
	if(c == 0 )
		printf("\n");
	return 0 ;
}
