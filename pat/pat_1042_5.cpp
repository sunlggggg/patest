#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
string array1[55];
int main(){
	int k, i, j;
	/*string array1[55] = { "", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
		"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
		"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
		"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
		"J1", "J2" }*/;
	string *array2 = new string[55];
	stringstream ss;
	for (int i = 1; i <= 13; i++){
		ss.clear();
		ss << "S";
		ss << i;
		ss>>array1[i];
	}
	for (int i = 1; i <= 13; i++){
		ss.clear();
		ss.str("");
		ss << "H";
		ss << i;
		ss>>array1[i+13];
	}
	for (int i = 1; i <= 13; i++){
		ss.clear();
		ss.str("");
		ss << "C";
		ss << i;
		ss>>array1[i+13*2] ;
	}
	for (int i = 1; i <= 13; i++){
		ss.clear();
		ss.str("");
		ss << "D";
		ss << i;
		ss>>array1[i+13*3] ;
	}
	array1[53] = "J1";
	array1[54] = "J2";
	int change[55];
	cin >> k;
	for (i = 1; i<55; ++i){
		cin >> change[i];
	}
	for (i = 1; i <= k; ++i){
		if (i % 2 == 1){
			for (j = 1; j<55; ++j){
				array2[change[j]] = array1[j];
			}
		}
		else{
			for (j = 1; j<55; ++j){
				array1[change[j]] = array2[j];
			}
		}
	}
	if (k % 2 == 0){
		for (i = 1; i<55; ++i){
			cout << array1[i];
			if (i != 54)
				cout << " ";
		}
	}
	else{
		for (i = 1; i<55; ++i){
			cout << array2[i];
			if (i != 54)
				cout << " ";
		}
	}

}