//给予一个自然数无序序列 0 1 2 3 N-1
//0回到0，则与任意无序位置的数目交换 
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	int v[100100];//用来保存数字的位置
	cin>>n ; 
	int zeroI;
	int left = n -1;//除了0以外不再位置上的数
	for(int i = 0 ; i < n; i++){
		int t;
		cin>>t;
		if(t == i && t ) left--;
		v[t] = i ;//t的位置 是i
	}
	//1.只能移动0
	//2.最少移动次数 即使得有序
	int ans = 0 ;
	int k = 1;
	while(left > 0 ){ 
		if(v[0] == 0 ){
			for(; k < n ; k++ ){
				if(v[k] != k ){
					swap(v[0],v[k]);//找到一个不在位置上的数与之交换
					ans++;
					break;
				}
			}
		}
		while(v[0] != 0 ){
			swap(v[0],v[v[0]]);//0占据了v[0](不等于0)的位置 与之交换
			ans++;
			left--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
/**
1 2 0 3 4
*/
