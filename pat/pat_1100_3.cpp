/**
1100. Mars Numbers (20)
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
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication 
between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a 
number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
**/

#include<iostream>
#include<sstream>//getline
using namespace std;
string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string high[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
pair<int,int> getIndex(string s){ //pos 0 1
	for(int i = 0 ; i < 13 ; i++){
		if(low[i].compare(s) == 0){
			return make_pair(0,i);
		}
	}
	for(int i = 0 ; i < 12 ; i++){
		if(high[i].compare(s) == 0){
			return make_pair(1,i+1);
		}
	}
}

int mstoi(string s){
	stringstream ssm;
	ssm<<s;
	int i;
	ssm>>i;
	return i;
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	int n ;
	cin>>n;
	getchar();//读掉换行
	for(int i = 0 ; i < n ; i++){
		//读入一行
		string s;
		getline(cin,s);
		if(isdigit(s[0])){//数字
			int num = mstoi(s);
			if(num/13==0 ){ 
				printf("%s\n", low[num%13].c_str());
			}else{
				if(num%13 == 0 ){
					printf("%s\n", high[num/13%13-1].c_str()); //不用输出tret
				}else {
					printf("%s %s\n", high[num/13%13-1].c_str(),low[num%13].c_str());
				}
			}
		}else{
			int pos = s.find(" ");
			int num = 0 ;
			if(pos == -1){
				pair<int,int> pair = getIndex(s);
				if(pair.first == 0 ){//低位
					num+=pair.second;
				}else{
					num+=pair.second*13;
				}
			}else {
				pair<int,int> pair1 = getIndex(s.substr(pos+1,s.size()));
				pair<int,int> pair2 = getIndex(s.substr(0,pos));
				num+=pair1.second;
				num+=pair2.second*13;
			}
			printf("%d\n", num);
		}
	}
}