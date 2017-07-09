#include<iostream>
#include<queue>
#include<map>
#include<iterator>
using namespace std;
struct Customer
{

	int number;
	int servereTime;
};

//return the window index 
int minNowServerTimeWindow(queue<Customer *>  qu[], int windowNum){
	int min = -1;
	int minServerTime; 
	for (int i = 0; i < windowNum; i++){
		if (qu[i].size() != 0){
			if (min == -1){
				minServerTime = ((Customer *)(qu[i].front()))->servereTime;
				min = i;
			}
			else{
				if (((Customer *)(qu[i].front()))->servereTime < minServerTime ) {
					min = i;
				}
			}
		}
	}
	return min;
}
#define MAX_WINDOWN_NUM  21
int main(){
	ios::sync_with_stdio(false);
	map<int, int> map;
	int windowNum, customerNum, yellowAreaNum, checkNum;
	cin >> windowNum >> yellowAreaNum >> customerNum >> checkNum;
	queue<Customer *> queue[MAX_WINDOWN_NUM];
	for (int i = 0; i < customerNum; i++){
		int serverTime;
		cin >> serverTime;
		Customer * customer = new Customer();
		customer->number = i + 1;
		customer->servereTime = serverTime;
		if (i < windowNum * yellowAreaNum)
			queue[i % windowNum].push(customer);
		else
			queue[windowNum].push(customer);
	}
	int nowTime = 0;
	int lastPop = -1;
	while (true)
	{
		int minserverTimeWindow = minNowServerTimeWindow(queue, windowNum);
		if (minserverTimeWindow == -1)
			break;
		int lastTime = nowTime; 
		nowTime += ((Customer *)(queue[minserverTimeWindow].front()))->servereTime;
		if (lastTime < 540){
			map[((Customer *)(queue[minserverTimeWindow].front()))->number] = nowTime ;
		}
		else{
			map[((Customer *)(queue[minserverTimeWindow].front()))->number] = -1;
		}
		
		bool isFinishPush = false;
		for (int j = 0; j < windowNum; j++){
			if (j != minserverTimeWindow &&  queue[j].size()> 0){
				((Customer *)(queue[j].front()))->servereTime -= ((Customer *)(queue[minserverTimeWindow].front()))->servereTime;
			}
			if (queue[j].size() == 0 && isFinishPush == false){
				if (queue[windowNum].size() > 0){
					((Customer *)(queue[windowNum].front()))->servereTime -= ((Customer *)(queue[minserverTimeWindow].front()))->servereTime;
					queue[j].push(queue[windowNum].front());
					queue[windowNum].pop();
				}
				queue[minserverTimeWindow].pop();
				lastPop = j;
				isFinishPush = true;
			}
		}
		if (isFinishPush == false){
			queue[minserverTimeWindow].pop();
			if (queue[minserverTimeWindow].size() < queue[lastPop].size()){
				if (queue[windowNum].size() > 0){
					queue[minserverTimeWindow].push(queue[windowNum].front());
					queue[windowNum].pop();
				}

				lastPop = minserverTimeWindow;
			}
			else if (queue[minserverTimeWindow].size() > queue[lastPop].size()){
				if (queue[windowNum].size() > 0){
					queue[lastPop].push(queue[windowNum].front());
					queue[windowNum].pop();
				}
			}
			else if (minserverTimeWindow < lastPop){
				if (queue[windowNum].size() > 0){
					queue[minserverTimeWindow].push(queue[windowNum].front());
					queue[windowNum].pop();
				}
				lastPop = minserverTimeWindow;
			}
			else{
				if (queue[windowNum].size() > 0){
					queue[lastPop].push(queue[windowNum].front());
					queue[windowNum].pop();
				}
			}
		}

	}
	for (int i = 0; i < checkNum; i++){
		int nowNumber;
		cin >> nowNumber;
		int time = map[nowNumber];
		if (time == -1){
			printf("Sorry\n");
		}
		else{
			int hour = time / 60 + 8;
			int min = time % 60;
			printf("%02d:%02d\n", hour, min);
		}
	}
}
