#include<iostream>
#include<string>
#include<cmath>
#include<deque>
using namespace std;
int findK(int len){
	int k;
	int n2 = 3;
	while (n2 <= len){
		if ((len - n2) % 2 == 0 && ((len - n2) / 2 + 1) <= n2){
			return (len - n2) / 2 + 1;
		}
		n2++;
	}
}
void printSpace(int n){
	while (n--){
		cout << " ";
	}
}
int main(){
	ios::sync_with_stdio(false);
	char ch;
	deque<char> d;
	while ((ch = getchar()) != '\n'){
		d.push_back(ch);
	}
	//string s;
	//cin >> s;
	
	//for (int i = 0; i < s.length(); i++)
    //	d.push_back(s[i]);
	int l = d.size();
	int n1 = findK(l);
	
	for (int i = 0; i < n1 ; i++){
		if (i != n1 - 1){
			cout << d.front();
			d.pop_front();
			printSpace(l - 2*n1);
			cout << d.back();
			d.pop_back();
			cout << endl;
		}
		else{
			for (int i = 0; i < d.size(); i++ ){
				cout << d[i];
			}
			cout << endl;
		}
	}
	return 0;
}