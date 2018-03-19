#include<iostream>  
#include<stdio.h>  
#include<vector>  
#include<algorithm>  
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long A, B, C;
	long long sum;
	int i = 1;
	while (T--)
	{
		cin >> A >> B >> C;
		sum = A + B;
		if (A>0 && B>0 && sum<0)
			printf("Case #%d: true", i++);
		else if (A<0 && B<0 && sum >= 0)
			printf("Case #%d: false", i++);
		else  if (sum> C)
			printf("Case #%d: true", i++);
		else
			printf("Case #%d: false", i++);
		cout << endl;
	}
}