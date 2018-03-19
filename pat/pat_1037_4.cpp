#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n1,n2;
	vector<int> v1,v2;
	cin >> n1;
	int t;
	for(int i = 0; i< n1;i++){
		cin>>t;
		v1.push_back(t);
	}
	cin>>n2;
	for(int i = 0; i< n2;i++){
		cin>>t;
		v2.push_back(t);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int i =0 ,j ,ans =0;
	while(i< n1&& i <n2&&v1[i]<0 && v2[i]<0){
		ans += v1[i]*v2[i];
		i++;
	}
	i = n1 - 1;
	j = n2 - 1;
	while(i>= 0 && j >= 0 &&v1[i]>0 && v2[j] >0 ){
		ans+=v1[i]*v2[j];
		i--;j--;
	}
	printf("%d\n",ans);
	return 0;
}

/*
4
1 2 4 -1
4
7 6 -2 -3
*/