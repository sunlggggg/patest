/**
1071. Speech Patterns (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the 
cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's 
still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by 
a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it 
has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in 
all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters 
or the line beginning/end.

Note that words are case insensitive.

Sample Input:
Can1: "Can a can can a    can???  It can!"
Sample Output:
can 5
**/

#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct cmp{
	bool operator()(const pair<string,int> a, const pair<string , int> b) const {
		return a.second>b.second;
	}
};

int main(){
	string s;
	getline(cin,s);
	map<string,int> m;
	int last = 0;
	for(int i  = 0; i < s.size();i++){
		if(!isalpha(s[i])&&!isdigit(s[i])){
			string t = s.substr(last,i-last);
			if(t.size() == 0) continue;
			for(int k = 0 ; k < t.size(); k++){
				if(isalpha(t[k])){
					t[k] = tolower(t[k]);
				}
			}
			if(m.count(t) == 0 ){
				m[t] = 0;
			}
			m[t]++;
			i++;
			while(i<s.size()){//找到第一个有效字符
				if(isalpha(s[i])||isdigit(s[i])){
					last = i;
					break;
				}
				i++;
			}
		}
	}	
	//sort(v.begin(),v.end(),cmp());
	int max = -1;
	for(map<string,int>::iterator rt; rt!=m.end();rt++){
		if(rt->second>max){
			max =rt->second;
			s = rt->first;
		}
	}
	printf("%s %d\n",s.c_str(),max);
	return 0;
}