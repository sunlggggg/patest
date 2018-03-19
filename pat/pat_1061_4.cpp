#include<iostream>

#include<string>
using namespace std;
string sameC(string a, string b){
	int i = 0 ;
	string s;
	while(i<a.length()&&i<b.length()){
		if(a[i] == b[i]&& isupper(a[i]) && a[i] <= 'G'){
			s.push_back(a[i]);
			i++;
			break;
		}
		i++;
	}
	while(i<a.length()&&i<b.length()){
		if(a[i] == b[i]&& ((isupper(a[i]) && a[i] <= 'N')|| isdigit(a[i]))){
			s.push_back(a[i]);
			return s;
		}
		i++;
	}
}
int sameS(string a, string b){
	int i = 0 ;
	string s;
	while(i<a.length()&&i<b.length()){
		if(a[i] == b[i]&& isalpha(a[i])){
			return i;
		}
		i++;
	}
}
string we[] ={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
	while(1)
	{
		string a,b,c,d;
		cin >> a >> b >> c >> d;
		string s_s = sameC(a,b);
		
		cout<<we[s_s[0]-'A']<<" " ;
		if(isdigit(s_s[1])){
			printf("%02d",s_s[1] - '0');	
		}else{
			cout<<s_s[1]-'A' + 10 ;
		}
		cout<<":";
		int c_c = sameS(c , d);
		printf("%02d",c_c);
	}
	return  0;
}