#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;
int main(){
	int k;
	string s;
	set<char> ok;
	string stuck;
	cin>>k;
	cin>>s;
	vector<string> v;
	vector<string>::iterator it;
	while(s.size()>0){
		int inx = s.find_first_not_of(s[0]);
		//e(0)eeer(4)
		if(inx > k){
			v.push_back(s.substr(0,k));
			s = s.substr(k);
		}
		else if(inx == -1){
			if(s.size()<=k){
				v.push_back(s);
				s = "";
			}else{
				v.push_back(s.substr(0,k));
				s = s.substr(k);
			}
		}else{
			v.push_back(s.substr(0,inx));
			s = s.substr(inx);
		}
	}
	it = v.begin();
	while(it!=v.end()){
		string str = *it;
		if(str.size() < k ){
			ok.insert(str[0]);
		}
		it++;
	}
	it = v.begin();
	while(it!=v.end()){
		string str = *it;
		if(ok.count(str[0]) == 0 ){//stuck
			if(stuck.find(str[0])==-1){
				stuck.push_back(str[0]);
			}
			*it = str.substr(0,1);
		}
		it++;
	}
	if(stuck.size()){
		cout<<stuck<<endl;
	}
	for(int i = 0 ; i < v.size() ; i++){
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}
//3
//caseee1__thiiis_iiisss_a_teeeeeest