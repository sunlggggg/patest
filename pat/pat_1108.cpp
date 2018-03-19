#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;
double _stod(string s){
	stringstream ssm;
	ssm<<s;
	double ans;
	ssm>>ans;
	return ans;
}
bool isDight(string s){
	int i = 0 ;
	if(s[0] == '-'){
		i = 1;
	}
	int po =  0;
	for( ;i < s.size(); i++){
		if(!isdigit(s[i])){
			if(!(po == 0 && s[i] == '.')){
				return false;
			}
		}
	}
	if(s.find('.')!=-1){
		int px = s.find_first_of('.') ;
		if(s.size() - px -1 > 2 ){
			return false;
		}
	}
	double as = _stod(s);
	if(abs(as +1000.0) < 0.00001 ||abs(as  -1000.0) < 0.00001 )
		return true;
	if(as < -1000||as > 1000){
		return false;
	}
	return true;
}

int main(){
	int n;
	vector<double> v;
	cin>>n;
	string s;
	int cnt = 0 ;
	double ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		cin>>s;
		if(isDight(s)){
			cnt++;
			ans+=_stod(s);
		}else{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
	}
	if(cnt == 0 ){
		cout<<"The average of 0 numbers is Undefined"<<endl;
	}else if(cnt != 1){
		printf("The average of %d numbers is %.2lf",cnt,ans/cnt);
	}else if(cnt == 1){
		cout<<"The average of 1 number is "<<ans<<endl;
	}
	return 0;
}

/**
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
**/