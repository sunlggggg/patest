#include<iostream>
#include<string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cstring>
using namespace std; 
string IntToString(int num );
int main(){
	int a ; 
	int b ; 
	cin >> a ; 
	cin >> b; 
	int sum = a + b ;
	if(sum < 0 )
		cout<<"-";
	string strSum = to_string((long long )abs(sum));
	for(int i = 0 ; i < strSum.length(); i ++ ){
		cout<<strSum[i];
		if((strSum.length() - i ) % 3 == 1 && i != strSum.length() -1 ){
			cout<<",";
		}
	}
	return 0 ; 
}
string IntToString(int num ){
	while() {

	}
}