#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn  = 10010;
double arr[maxn];
void insertSort(double *a, int s, int n){
	int needInsert = a[s];
	int i ;
	for(i = s+1; i< n ; i++){
		if(needInsert>a[i]){
			a[i-1] = a[i];
		}else{
			break;
		}
	}
	a[i-1] = needInsert;
}
int main(){
#ifdef _DEBUG
	string _s;
	cin>>_s;
	freopen(_s.c_str(),"r",stdin);
#endif
	int n ;
	cin>>n;
	double arr_[10] = {2.0,1.0,3.0};
	insertSort(arr_,0,3);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lf",&arr[i]);
	}
	sort(arr,arr+n);//ÅÅÐò
	for(int i =  0; i < n -1 ; i++){
		arr[i+1] = 0.5*(arr[i]+arr[i+1]);
		insertSort(arr,i+1,n);
	}
	int ans = (int)(arr[n-1]+0.5);
	cout<<ans<<endl;
	return 0;
}
