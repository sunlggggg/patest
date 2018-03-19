#include<iostream>
#include<stack>
using namespace std;
int main(){
	/*
	Calculate a + b and output the sum in standard format --
	that is, the digits must be separated into groups of three by commas
	(unless there are less than four digits).

	Input

	Each input file contains one test case.Each case contains a pair of integers a and b where - 1000000 <= a, b <= 1000000. The numbers are separated by a space.

	Output

	For each test case, you should output the sum of a and b in one line.
	The sum must be written in the standard format.

	Sample Input
	- 1000000 9
	Sample Output
	- 999, 991
	*/

	int a, b;
	stack<char> s;
	cin >> a >> b;
	int c = a + b;
	int tmp = c;
	int cnt = 0;
	while (tmp){
		cnt++;
		int d = tmp % 10;
		s.push(char(abs(d) + '0'));
		tmp /= 10;
		if (cnt % 3 == 0 && tmp != 0)
			s.push(',');
	}
	if (c < 0)
		s.push('-');
	if (s.size() == 0)
		cout << 0 << endl;
	while (s.size() > 0){
		cout << s.top();
		s.pop();
	}
	return 0;
}