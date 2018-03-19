#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	int n;
	vector<int> v(100010);
	cin>>n;
	for(int i =  0 ; i< n ; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.begin() + n,greater<int>());
	int ans = 0 ;
	for (int i = 0; i < n; i++) {
		if (i + 1 < v[i]) {
			ans = i + 1;
		} else {
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
