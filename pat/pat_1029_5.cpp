#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int A1[1000000],A2[1000000];
	int n , m ; 
	scanf("%d",&n);
	int i , j ;
	for(i = 0 ; i < n ;i++){
		scanf("%d",&A1[i]);
	}
	scanf("%d",&m);
	for(int j = 0 ; j < m  ;j++){
		scanf("%d",&A2[j]);
	}
	i = 0 ; j = 0 ; 
	int nowC = 0 ;
	int med =  (m+n)/2 ;
	if((m+n)%2 == 0 ){
		med-= 1;
	}
	while(i < n && j < m ){
		nowC = i + j ;
		if(nowC == med ){
			if(A1[i]<=A2[j]){
				printf("%d\n",A1[i]);
			}else {
				printf("%d\n",A2[j]);
			}
			break;
		}else {
			if(A1[i]<=A2[j]){
				i++;
			}else {
				j++;
			}
		}
		if(i == n ){
			while(j<m){
				nowC = i + j ;
				if(nowC == med ){
					printf("%d\n",A2[j]);
					break;
				}
				j++;
			}
		}else if(j == m ){
			while(i<n){
				nowC = i + j ;
				if(nowC == med ){
					printf("%d\n",A1[i]);
					break;
				}
				i++;
			}
		}
	}

	//int A1[2000000];//需要开那么大。。
	//int n , m ; 
	//scanf("%d",&n);
	//int i , j ;
	//for(i = 0 ; i < n ;i++){
	//	scanf("%d",&A1[i]);
	//}
	//scanf("%d",&m);
	//for(int j = i ; j < m +n ;j++){
	//	scanf("%d",&A1[j]);
	//}
	//sort(A1,A1+m+n);
	//if((m+n)%2 == 0){
	//	printf("%d\n",A1[(m+n)/2 - 1]);
	//}else {
	//	printf("%d\n",A1[(m+n)/2 ]);
	//}
	return 0;
}

/**
1 1
4 2 3 4 5
*/
