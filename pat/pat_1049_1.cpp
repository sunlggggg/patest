/**
1049. Counting Ones (30)
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N.
For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=2^30).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
**/
//����2
#include<iostream>
#include<sstream>
#include<string>
#define LL long long
using namespace std;
LL mstoLL(string s){
	if(s.size()==0)
		return (LL)(0);
	stringstream ssm;
	ssm<<s;
	LL t;
	ssm>>t;
	return t;
}
int main(){
	//3123
	//312--3--0 ��312����
	//3120 
	//312--0--0   (0��)
	//3123
	//31--2--3  31*10*10
	char n[25];
	scanf("%s",&n);
	string s(n);
	//0123
	LL c = 0 ;
	LL radix = 1;
	for(LL i = s.size() - 1; i>= 0 ; i--){
		string left = s.substr(0,i);
		string right = s.substr(i+1,s.size()-i-1);
		if(s[i] == '0'){
			//1230 0001-------1221 123��
			//1202 001X-------111X 12*10 = 120��
			c += mstoLL(left)*radix;
		}else if(s[i] == '1'){
			//1231 0001-----1221  + 1231
			//1213 001X-----111X 121(0123)
			c += mstoLL(left)*radix + 1 + mstoLL(right);
		}else{
			//1232 0001-----1221 1231
			//1232 001X-----122X 123X
			c += (mstoLL(left)+1)*radix;
		}
		radix*=10;
	}
	printf("%d\n",c);
	return 0 ;
}
//����1 
//ʹ�ñ��� 22�� 

//#include<iostream>
//using namespace std;
//int oneCount(int n){
//	int c = 0 ;
//	while(n>0){
//		int t = n%10;
//		if(t == 1)
//			c++;
//		n/=10;
//	}
//	return c;
//}
//int main(){
//	int n;
//	cin>>n;
//	int c = 0 ;
//	for(int i = 1;i<=n;i++){
//		c+=oneCount(i);
//	}
//	cout<<c<<endl;
//	return 0 ;
//}