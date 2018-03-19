//超出int 使用long long
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//arr 有序
int firstGreater(int arr[],int n ,int l,int h, int vl){ 
	if(arr[n-1]<=vl)
		return n;//全部小于等于 vl
	else{
		int mid ;
		while(l < h ){
			mid = (l+h)/2;
			if(arr[mid]<= vl )
				l = mid+1;
			else 
				h = mid;
		}
	}
	return l;
}
int main(){
	vector<long long> v;
	vector<long long>::iterator vt,vtt;
	int n , p ;
	cin>>n>>p;
	for(int i = 0 ; i < n ; i++){
		long long t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	
	int max1 = 1 ;
	for(int i = 0 ; i< n;i++) {
		long long min = v[i];
		long long max = p*min;
		vt = upper_bound(v.begin()+i+1,v.end(),max);
		
		int cnt = 0;
		vtt = v.begin()+i;
		cnt = vt - vtt;
		if(cnt > max1)
			max1 = cnt;
	}
	
	cout<<max1<<endl;
	return 0;
}
