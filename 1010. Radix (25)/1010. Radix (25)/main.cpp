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

	//������ܵ���С�Ľ�����
	for (int i = 0; i < n2.size(); i++)
	{   
		//����Ҫ+1
		minRadix = max(minRadix, (unsigned long long)(charToint(n2[i]) + 1));
	}

	bool flag = false;
	unsigned long long result = 0;
	unsigned long long r = sInt + 1;  //������Ϊ N1+1 
	unsigned long long l = minRadix;
	//ʹ�ö��ַ�ȥ���Һ��ʵ�radix
	while (l <= r) // ��С���� > ����� ˵�������� 
	{   //����С�Ľ�������ʼ����
		//�ҵ��м����
		unsigned long long j = (l + r) / 2;//û˵��j�����36����
		unsigned long long tInt = 0;
		for (int i = 0; i < n2.size(); i++)
		{//jΪt�Ľ����������t��j�����µ�ʮ���ƴ�С
			tInt = tInt*j + charToint(n2[i]);
			if (tInt > sInt)
			{//�����δͳ���꣬tInt�ͱ�sInt��û��Ҫ��ͳ����ȥ
				//˵��j����ʹ��tInt>sInt,t�Ľ�����Ҫ��jС
				break;
			}
		}
		if (tInt == sInt)
		{
			flag = true;
			result = j;
			break;
		}
		//˵�����ƴ��� �� ��С�ķ�����  
		else if (tInt > sInt)
		{
			r = j - 1;
			/*flag = false;
			break;*/
		}
		//˵������С�� �� ����ķ�����   
		else
			l = j + 1;
	}
	if (flag) 
		cout << result << endl;
	else 
		cout << "Impossible" << endl;
	return 0;
}