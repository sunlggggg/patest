//陷阱：一开始就相同
//难点：插入排序
//插入排序思路 1【0】 3【1】 4【2】
//tmp = A[3]
//case 1  插入 3 【3】
//1:tmp<A[2]  A[3] = A[2]
//2:tmp == A[1] A[2] = tmp;
//case 2 插入 0 【3】
//1:tmp<A[2] A[3] = A[2]
//2:tmp<A[1] A[2] = A[1]
//3:tmp<A[0] A[1] = A[0]
//4:A[0] = tmp 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//i:待插入位置
void insertSort(vector<int> &A, int n,int i){
	if(i == 0 ) return;
	int temp = A[i];
	int  j ;
	for(j=i ; j > 0 && A[j-1] > temp;j--)
	{
		A[j] = A[j-1];
	}
	A[j] = temp;
}
void insertSort(vector<int> &A){
	for(int i = 1; i < A.size(); i++ ){
		int tmp = A[i];
		int j ;
		for( j = i ; j > 0 &&A[j-1]>tmp;j--){
			A[j] = A[j - 1];
		}
		A[j] = tmp;
	}
}
//i: 1 2 4 8 ...
void mergeSort(vector<int> &A,int len){
	//0 - len-1  len - 2*len-1 
	int t = A.size()/len + 1;
	if(A.size()%len != 0 ) {
		t++;
	}
	if(t%2 != 0 ){
		t--;//最后一组不排序
	}
	for(int i = 0 ; i< t; i+=2){
		if((i+2)*len> A.size()){
			sort(A.begin()+i*len, A.end());
		}
		else {
			sort(A.begin()+i*len,A.begin()+(i+2)*len);
		}
	}
}
void mergeSort(vector<int> &A){
	for(int i =1 ; i <= A.size()+1; i*=2 ){
		mergeSort(A,i);
	}
}

bool equ(vector<int> A, vector<int> B){
	for(int i = 0 ; i < A.size();i++){
		if(A[i] != B[i])
			return false;
	}
	return true;
}
void p(vector<int> A){
	for(int i = 0; i < A.size();i++){
		if(i!= A.size() -1){
			printf("%d ",A[i]);
		}else{
			printf("%d\n",A[i]);
		}
	}
}
int main(){
	int n;
	vector<int> A1,A1_,A2;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		int t;
		scanf("%d",&t);
		A1.push_back(t);
		A1_.push_back(t);
	}
	for(int i = 0 ; i < n ; i++){
		int t;
		scanf("%d",&t);
		A2.push_back(t);
	}
	//insert sort
	for(int i = 1 ; i < n ; i++) {
		insertSort(A1,n,i);
		if(equ(A2,A1)){
			printf("Insertion Sort\n");
			insertSort(A1,n,i+1);
			p(A1);
			return 0;
		}
	}

	//merge sort
	for(int i =1 ; i <= A1_.size()*2+1; i*=2 ){
		mergeSort(A1_,i);
		if(equ(A2,A1_)){
			printf("Merge Sort\n");
			mergeSort(A1_,i*2);
			p(A1_);
			return 0;
		}
	}
	return 0 ;
}
/*
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6

4 
3 4 2 1
3 4 2 1

*/