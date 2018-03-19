#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){
	//while(1)
	{
		map<int,int> m;
		map<int,int>::iterator mt;
		vector<int> v;
		int n ;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			int s;
			cin >> s; 
			v.push_back(s); 
			set<int> in;//保证自己只是出现一次
			if(!m.count(s)){
				m[s] = 1;
				in.insert(s);
			}
			else if(!in.count(s)){
				m[s] ++;
				in.insert(s);
			}
		}
		int fff= 0 ;
		for(int i = 0 ; i < v.size(); i ++) {
			int s = v[i];
			bool f = true;
			mt = m.find(s);
			if(mt->second > 1){
				f = false;
			}
			if(f){
				fff = 1;
				cout<<s<<endl;
				break;
			}
		}
		if(!fff)
			cout<<"None"<<endl;

	}  
	return 0 ; 
}