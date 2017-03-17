#include<iostream>
#include<vector>
#include<string>
#include <strstream>
using namespace std;

void printByEnglish(int sum ){
	int f = 0; 
	strstream ss;
	string s;
	ss << sum;
	ss >> s;
	for (int i = 0; i < s.size(); i++ ){
		if (f != 0){
			cout << " ";
		}
		else{
			f = 1;
		}
		switch (s[i] - 48)
		{
		case 0:cout << "zero"; break;
		case 1:cout << "one";  break;
		case 2:cout << "two";  break;
		case 3:cout << "three";  break;
		case 4:cout << "four";  break;
		case 5:cout << "five";  break;
		case 6:cout << "six";  break;
		case 7:cout << "seven";  break;
		case 8:cout << "eight";  break;
		case 9:cout << "nine";  break;
		default:
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	string s; 
	cin >> s;
	int sum = 0; 
	for (int i = 0; i < s.size(); i++){
		sum += s[i] - 48 ;
	}
	printByEnglish(sum);
	return 0;
}