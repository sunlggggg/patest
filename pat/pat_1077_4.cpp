#include <iostream>
#include <string>
#include <vector>
#include <algorithm>//reverse(s.begin(),s.end())
using namespace std;
int main(){

	int n;
	string s, ans;
	vector<string> svec;
	cin >> n;
	getchar();
	while (n--){
		getline(cin, s);
		reverse(s.begin(), s.end());
		svec.push_back(s);
	}
	for (int i = 0; i < svec[0].size(); i++){
		bool flag = true;
		for (int j = 1; j < svec.size(); j++){
			if ( i > svec[j].size() -1 || svec[j][i] !=  svec[0][i]  ){
				flag = false;
				break;
			}
		}
		if (flag) ans +=  svec[0][i];
		else break;
	}
	if (ans.empty())
		cout << "nai" << endl;
	else{
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}