#include<iostream>
#include<string>
#include<cstdlib>
const int max_number = 10000;
using namespace std;
int tosec(string time){
	return atoi(time.substr(0, 2).c_str()) * 3600 + atoi(time.substr(3,2).c_str()) * 60 + atoi(time.substr(6, 2).c_str());
}
int main(){
	string names[max_number];
	int startTime[max_number];
	int endTime[max_number];
	int m; 
	cin >> m; 
	for (int i = 0; i < m; i++){
		cin >> names[i];
		string timeTmp;
		cin >> timeTmp; 
		startTime[i] = tosec(timeTmp);
		cin >> timeTmp;
		endTime[i] = tosec(timeTmp);
	}
	int minTime = startTime[0];
	int minIndex = 0; 
	for (int i = 0; i < m; i++){
		if (startTime[i] < minTime){
			minIndex = i;
			minTime = startTime[i];
		}
	}

	cout << names[minIndex] << " ";

	int maxTime = endTime[0];
	int maxIndex = 0;
	for (int i = 0; i < m; i++){
		if (endTime[i] > minTime){
			maxIndex = i;
			maxTime = endTime[i];
		}
	}
	cout << names[maxIndex] ;
	return 0; 
}