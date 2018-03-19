#include<iostream>
#include<deque>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	long long N, B;
	deque<int> s;
	cin >> N >> B;
	if (N == 0){  //1
		s.push_back(0);
	}
	while (N){
		s.push_front(N%B);
		N /= B;
	}
	bool flag = true;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]){
			flag = false;
			break;

		}
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < s.size() ; i++){
		cout << s[i] ;
		if (i != s.size() - 1){
			cout << " ";
		}
	}
	
	return 0;
}
// 0的处理 没有输出
