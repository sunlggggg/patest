#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
struct A{
	string d;
	string t;
};
string di[] = {
	"ling","yi","er","san","si","wu","liu","qi","ba","jiu",
};
string ti[] = {"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};

//连续两个0
vector<A> v; 
vector<string> rtv;
vector<A>::iterator vt; 

//
bool isAllZero(string s){
	stringstream ssm;
	ssm<<s;
	int a;
	ssm>>a;
	return !a;
}
void pp(string a,string b,string c ,int l){
	rtv.clear();
	if(!isAllZero(a)){
		rtv.push_back(di[a[0]-'0']);
		rtv.push_back("Yi");
	}
	int f_is0 = 0;
	if(!isAllZero(b)){
		for(int i = 0; i< b.size();i++){
			if(b[i] == '0'){
				if(f_is0== 1 ){
					continue;//跳过
				}else{
					f_is0 = 1;
					rtv.push_back(di[0]);
				}
			}else {
				rtv.push_back(di[b[i] - '0']);
				if(ti[b.size() - i - 1] !=""){
					rtv.push_back(ti[b.size() - i - 1]);
				}
				f_is0 = 0;
			}
		}
		//去除lingwan
		if(rtv.at(rtv.size() - 1 ) == "ling"){
			vector<string>::iterator it = rtv.end() ;
			it--;
			rtv.erase(it);
		}
		rtv.push_back("Wan");
	}
	//首位非0
	if(c[0] != '0'  && l>4 && isAllZero(b)){
		rtv.push_back("ling");
	}
	f_is0 = 0;
	if(!isAllZero(c)){
		for(int i = 0; i  < c.size();i++){
			if(c[i] == '0'){
				if(f_is0 == 1 ){
					continue;//跳过
				}else{
					f_is0=1;
					rtv.push_back(di[0]);
				}
			}else {
				rtv.push_back(di[c[i] - '0']);
				if(ti[c.size() - i - 1] !=""){
					rtv.push_back(ti[c.size() - i - 1]);
				}
				f_is0 = 0;
			}
		}
	}
	if(rtv.at(rtv.size() - 1 ) == "ling"){
		vector<string>::iterator it = rtv.end() ;
		it--;
		rtv.erase(it);
	}

	for(int i = 0 ; i < rtv.size();i++){
		
		cout<<rtv[i];
		if(i < rtv.size() - 1)
			cout<<" ";
	}
}



void p(string s){
	string a,b,c;
	a= b= c = "0";
	if(s.size() <= 4){
		c = s;
	}else if(s.size()  <= 8 ){
		c = s.substr(s.size() - 4, 4);
		b = s.substr(0,s.size() - 4 );
	}
	else if(s.size() == 9 ){
		c = s.substr(s.size() - 4, 4);
		b = s.substr(s.size() - 8, 4 );
		a =s[0];
	}
	pp(a,b,c,s.size());
}

int main(){
	ios::sync_with_stdio(false);
	while(1)
	{
		string s;
		cin >> s;
		if(s[0] == '0'){
			cout<<di[0];
			return 0;
		}
		if(s[0] =='-') {
			if(s[1]=='0'){
				cout<<"ling";
				return 0;
			}
			else{
				cout<<"Fu ";
				s = s.substr(1,s.size());
			}
		}
		p(s);
	}
	return 0 ;
}