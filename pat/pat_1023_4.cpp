/**
1023. Have Fun with Numbers (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 
246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the 
result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the 
resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the 
original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
**/
//permutation 排列
#include<iostream>
#include<string>
#include<map>
#include<vector>
#define LL long long
using namespace std;
//相同组合
bool isSamePermutation(string s,string t){
	map<char,int> m1,m2;
	for(int i = 0 ; i < s.size(); i++){
		if(m1.count(s[i]) == 1){
			m1[s[i]]++;
		}else{
			m1[s[i]] = 1;
		}
	}
	for(int i = 0 ; i < t.size(); i++){
		if(m2.count(t[i]) == 1){
			m2[t[i]]++;
		}else{
			m2[t[i]] = 1;
		}
	}
	if(m1.size() != m2.size())return false;
	else {
		vector<pair<char,int>> v1(m1.begin(),m1.end());
		vector<pair<char,int>> v2(m2.begin(),m2.end());
		for(int i = 0 ; i < v1.size(); i++ ){
			if(v1[i].second != v2[i].second)
				return false;
		}
		return true;
	}
}
bool hasAll(string s){
  bool f[10] = {false};
  for(int i = 0 ; i < s.size() ; i++ ){
    f[(int)(s[i]-'0')] = true;
  }
  bool flag = true;
  for(int i= 1 ; i < 10 ; i++){
    if(f[i] == false){
      flag = false;
      break;
    }
  }
  return flag ;
}
//大整数加法。。。 
//
string DoubIt(string s){
	//使用进位
	int Q = 0 ;
	for(int i = s.size()- 1 ; i >= 0 ; i-- ){
		if((s[i] - '0')*2 +Q >= 10 ){
			s[i]= char('0' + (s[i] - '0')*2  +Q - 10);
			Q = 1;
		}else {
			s[i]= char('0' + (s[i] - '0')*2 +Q );
			Q = 0 ;
		}
	}
	if(Q){
		s.insert(s.begin(),'1');
	}
	return s;
}
int main(){
	char t[25];
	scanf("%s",&t);
	string s(t);
	string sdou = DoubIt(s);
	if(hasAll(s)&&hasAll(sdou)&&isSamePermutation(s,sdou)){
		printf("Yes\n");
	}else 
		printf("No\n");
	printf("%s\n",sdou.c_str());
	return 0 ; 
}