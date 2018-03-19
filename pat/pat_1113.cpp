#include<iostream>
#include<algorithm>

using namespace std;
#define LL long long
const LL N =  100100;
LL arr[N];
bool cmp(LL a, LL b){
	return a> b ; 
}
LL _sum(LL L , LL H){
	LL sum = 0 ;
	for(LL i = L; i< H;i++ ){
		sum+=arr[i];
	}
	return sum;
}
int main(){
	LL n;
	cin>>n;
	for(LL i =0  ; i <  n ; i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,cmp);
	if(n % 2 == 1){//ÆæÊý
		cout<<"1 ";
		//3 2 1
		LL sum1 = _sum(0,n/2+1);
		LL sum2 = _sum(n/2+1,n);
		cout<<sum1-sum2<<endl;
	}else{
		cout<<"0 ";
		// 2 1
		LL sum1 = _sum(0,n/2);
		LL sum2 = _sum(n/2,n);
		cout<<sum1-sum2<<endl;
	}
	return 0;
}