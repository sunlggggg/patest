#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Sta{
	double dis;
	double price;
};
bool cmp(Sta a , Sta b){
	return a.dis < b.dis;
}
int main(){
	double maxC,dis,perdis;
	int sta_number;
	vector<Sta> v;
	cin>>maxC>>dis>>perdis>>sta_number;
	for(int i = 0 ; i < sta_number; i++) {
		Sta sta;
		cin >>sta.price >> sta.dis ;
		v.push_back(sta);
	}
	Sta end;
	end.dis =  dis;
	end.price = 0 ;
	v.push_back(end);
	sort(v.begin(),v.end(),cmp);  
	double maxRun = perdis*maxC;
	if(v.size() == 0 || v[0].dis >  0 ){
		printf("The maximum travel distance = 0.00");
	} else {
		int now  = 0 ; 
		double nowTank = 0 ,ans=0;
		while(now < sta_number){
			int min_index = -1 ;//最小或者最近低于当前（可达是前提）
			double priceMin = 100000000;
			for(int i = now+1;i <= sta_number&&v[i].dis -v[now].dis <= maxRun;i++){
				if(v[i].price < priceMin ){
					priceMin = v[i].price;
					min_index = i ; 
					if(priceMin < v[now].price)
						break;
				}
			}
			if(min_index == -1)
				break;
			double need = (v[min_index].dis-v[now].dis)/perdis;
			if(priceMin < v[now].price){
				if(nowTank<need){
					ans +=(need - nowTank )*v[now].price;
					nowTank = 0 ;
				}else{
					nowTank -= need;
				}
			}else {
				ans+=(maxC-nowTank)*v[now].price;
				nowTank=maxC-need;
			}
			now = min_index;
		}
		if(now == sta_number ){
			printf("%.2f\n",ans);
		}else {
			printf("The maximum travel distance = %.2f",v[now].dis+maxRun);
		}
	}
	return 0;
}

/**
50 1300 12 1
7.10 0
*/