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

void swap(string &s1, string &s2){
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
}
int main(void) {
	ios::sync_with_stdio(false);
	string n1, n2;
	int tag;
	unsigned long long radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
		swap(n1, n2);
	unsigned long long sInt = 0;
	//to 10 radix 
	for (int i = 0; i < n1.size(); i++)
	{   
		sInt = sInt*radix + charToint(n1[i]);
	}

	unsigned long long minRadix = 2;

	//求出可能的最小的进制数
	for (int i = 0; i < n2.size(); i++)
	{   
		//进制要+1
		minRadix = max(minRadix, (unsigned long long)(charToint(n2[i]) + 1));
	}

	bool flag = false;
	unsigned long long result = 0;
	unsigned long long r = sInt + 1;  //最大进制为 N1+1 
	unsigned long long l = minRadix;
	//使用二分法去查找合适的radix
	while (l <= r) // 当小进制 > 大进制 说明不存在 
	{   //从最小的进制数开始遍历
		//找到中间进制
		unsigned long long j = (l + r) / 2;//没说明j最大是36进制
		unsigned long long tInt = 0;
		for (int i = 0; i < n2.size(); i++)
		{//j为t的进制数，求出t在j进制下的十进制大小
			tInt = tInt*j + charToint(n2[i]);
			if (tInt > sInt)
			{//如果尚未统计完，tInt就被sInt大，没必要再统计下去
				//说明j进制使得tInt>sInt,t的进制数要比j小
				break;
			}
		}
		if (tInt == sInt)
		{
			flag = true;
			result = j;
			break;
		}
		//说明进制大了 ， 往小的方向走  
		else if (tInt > sInt)
		{
			r = j - 1;
			/*flag = false;
			break;*/
		}
		//说明进制小了 ， 往大的方向走   
		else
			l = j + 1;
	}
	if (flag) 
		cout << result << endl;
	else 
		cout << "Impossible" << endl;
	return 0;
}