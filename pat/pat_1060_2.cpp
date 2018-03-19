/**
1060. Are They Equal (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both
saved as 0.123*105 with simple chopping. Now 
given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal
in that machine.

Input Specification:

Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant 
digits, and A and B are the two float numbers to 
be compared. Each float number is non-negative, no greater than 10^100, and that its total digit number is less than 100.

Output Specification:

For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form 
"0.d1...dN*10^k" (d1>0 unless the number is 0); or
"NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a 
space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
**/
#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
bool isAllZero(string s){
	bool  rt = true;
	for(int i = 0 ; i<s.size(); i++){
		if(s[i] == '.') continue;
		else if(s[i] != '0') {
			rt = false;
			break;
		}
	}
	return rt;
}
string mitos(int i){
	stringstream ssm;
	ssm<<i;
	string s;
	ssm>>s;
	return s;
}
string ff(string s, int n ){
	//处理0和0.000
	if(isAllZero(s)){
		s ="0.";
		for(int i = 0 ; i < n ; i++){
			s.push_back('0');
		}
		s.append("*10^0");
		return s;
	}
	//删除头顶0
	bool flag = true;
	while(flag){
		if(s[0] == '0' && flag){
			s.erase(s.begin());
		}else {
			flag = false;
		}
	}
	
	if(n != 0){
		if(s[0] != '.'){
			//是否有小数点
			int len = s.size(); //整数长度
			int pos = s.find('.');
			if(pos != -1){
				len = pos; //123.12 
				s.erase(s.begin()+len); //删除小数
			}
			s.insert(s.begin(),'0');
			s.insert(s.begin()+1,'.');
			//补充0
			for(int i = 0 ; i < n - len ; i++){
				s.push_back('0');
			}
			s = s.substr(0, 2+n);
			s.append("*10^"+mitos(len));
		}else { 
			//.00012
			int len = s.size();
			bool flag = true;
			int c = 0 ;
			for(int i = 0 ; i<s.size(); i++){
				if(s[i] == '.') continue;
				else if(s[i] == '0'&& flag ) {
					c++;
				}else{
					flag = false;
				}
			}
			s = "0." + s.substr(c+1,s.size());
			for(int i = 0 ; i < n - len ; i++){
				s.push_back('0');
			}
			s = s.substr(0, 2+n);
			s.append("*10^"+mitos(-1*c));
		}
	}
	return s;
}
int main(){
	int n;
	string s1,s2;
	cin>>n;
	cin>>s1>>s2;
	s1 =ff(s1,n);
	s2 = ff(s2,n);
	if(s1.compare(s2) == 0){
		cout<<"YES " <<s1<<endl;
	}else {
		cout<<"NO " <<s1<<" "<<s2<<endl;
	}
	return 0;
}