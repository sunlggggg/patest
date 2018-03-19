/**
1098. Insertion or Heap Sort (25)
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
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
**/
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 110;
int n;
int origin_heap[maxn];
int origin[maxn];
int des[maxn];
void InsortSort( int ite){
	//分为0-ite ite-n-1
	int needInsert = origin[ite];
	int i ;
	for(i = ite ; i > 0&&origin[i-1] > needInsert ; i--){
		origin[i] = origin[i-1];
	}
	origin[i] = needInsert;
}
bool isSame(int *a , int *b){
	for(int i = 0 ; i < n ; i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}
void p(){
	for(int i = 0 ; i< n ; i++){
		printf("%d",origin[i]);
		if(i!= n-1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
}
void p2(){
	for(int i = 0 ; i< n ; i++){
		printf("%d",origin_heap[i]);
		if(i!= n-1){
			printf(" ");
		}else{
			printf("\n");
		}
	}
}
//调整堆 i 为待调整节点 向下调整 n为有效节点数目
void adjust(int i , int n ){
	int chi = 2*i+1;//左孩子
	while(chi < n ){//存在孩子
		if(chi +1 < n && origin_heap[chi+1]>origin_heap[chi]){
			chi++;//右孩子大
		}
		if(origin_heap[chi] > origin_heap[i]){
			swap(origin_heap[i],origin_heap[chi]);
			i = chi;
			chi = i*2+1;
		}else{
			break;
		}
	}
}

//从0开始
void heapsort(){
	//建堆0 1 2
	for(int i = n/2-1 ; i >= 0 ; i--){
		adjust(i,n);
	}
	for(int i = n-1; i >=0 ; i--) {
		swap(origin_heap[0],origin_heap[i]);
		adjust(0,i);
		if(isSame(origin_heap,des)){
			swap(origin_heap[0],origin_heap[i-1]);
			adjust(0,i-1);
			p2();
			return;
		}
	}
}
int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d",&n);
	for(int i = 0 ; i< n ; i++){
		scanf("%d",&origin[i]);
		origin_heap[i] = origin[i];
	}
	for(int i = 0 ; i< n ; i++){
		scanf("%d",&des[i]);
	}
	bool f = true;
	for(int i = 1; i < n ; i++){ // 中间序列和初试序列相同的情况....
		InsortSort(i);
		if(isSame(origin,des)){
			f =false;
			printf("Insertion Sort\n");
			InsortSort(i+1);
			p();
			break;
		}
	}
	if(f){
		printf("Heap Sort\n");
		heapsort();
	}
	return 0;
}