/**
Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. 
For example, given the sequence {0.1, 0.2, 0.3, 0.4}, 
we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4).

Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 
segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than
105. The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.

Output Specification:

For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.

Sample Input:
4
0.1 0.2 0.3 0.4 
Sample Output:
5.00
**/
//迭代1
//假设没有重复
//排序
//遍历
//超时
//迭代2
//优化
//统计每个数出现的次数 
//迭代2
//0 位置上出现n次 
//1 位置上出现n-1+n-1次
//2 n-2 * 3
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	double v, ans = 0;
	for(int i = 0; i<n;i++){
		scanf("%lf",&v);
		ans+=v*(i+1)*(n-i);
	}
	printf("%.2f\n",ans);
	return 0 ;
}
//迭代1
//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
//	int n;
//	double A[100010];
//	scanf("%d",&n);
//	for(int i = 0 ; i<n;i++){
//		scanf("%lf",&A[i]);
//	}
//	double rt = 0;
//	for(int i = 0 ; i < n ;i++){
//		double t = 0;
//		for(int k = i ; k < n ; k ++){
//			t+= A[k];
//			rt+=t;
//		}
//	}
//	printf("%.2lf",rt);
//	return 0 ;
//
//}
