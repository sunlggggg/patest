#include<iostream>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int now = 0, next = 0, total = 0;
	while (N--){
		cin >> next;
		if (next > now){
			total += (next - now) * 6 + 5;
		}
		else
			total += (now - next) * 4 + 5;
		now = next;
	}
	cout << total << endl;
	return 0;
}