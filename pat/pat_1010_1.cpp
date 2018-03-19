#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int charToint(char c)
{
	if (c <= '9'&&c >= '0')
		return c - '0';
	else if (c <= 'z'&&c >= 'a')
		return c - 'a' + 10;
	else return 0;
}
int main(void) {
	string n1, n2;
	int tag;
	unsigned long long radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
		swap(n1, n2);
	unsigned long long t1 = 0 ,t2 = 0;
	for (int i = 0; i < n1.size(); i++)
	{   
		t1 = t1*radix + charToint(n1[i]);
	}

	unsigned long long minRadix = 2;

	for (int i = 0; i < n2.size(); i++)
	{   
		minRadix = max(minRadix, (unsigned long long)(charToint(n2[i]) + 1));
	}

	bool flag = false;
	unsigned long long result = 0;
	unsigned long long L = minRadix;
	unsigned long long H = max(t1 + 1,L+1); 
	unsigned long long  M; 
	while (L <= H)
	{   
		M = (L + H) / 2;
		t2 = 0 ;
		for (int i = 0; i < n2.size(); i++)
		{
			t2 = t2*M + charToint(n2[i]);
			if (t2 > t1)
			{
				break;
			}
		}
		if (t2 == t1)
		{
			flag = true;
			break;
		}
		else if (t2 > t1)
		{
			H= M- 1;
		}
		else
			L = M + 1;
	}
	if (flag) 
		cout << M << endl;
	else 
		cout << "Impossible" << endl;
	return 0;
}