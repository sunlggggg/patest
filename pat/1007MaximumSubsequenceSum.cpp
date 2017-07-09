#include<iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n, flag = 0, sum = -1, temp = 0, left = 0, right = 0, tempindex = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] >= 0)
			flag = 1;
		temp = temp + v[i];
		if (temp > sum) {
			sum = temp;
			left = tempindex;
			right = i;
		}
		else if (temp < 0) {
			temp = 0;
			tempindex = i + 1;
		}
	}
	if (flag == 0)
		printf("0 %d %d", v[0], v[n - 1]);
	else
		printf("%d %d %d", sum, v[left], v[right]);
	return 0;
}