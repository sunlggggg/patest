//����һ����Ȼ���������� 0 1 2 3 N-1
//0�ص�0��������������λ�õ���Ŀ���� 
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	int v[100100];//�����������ֵ�λ��
	cin>>n ; 
	int zeroI;
	int left = n -1;//����0���ⲻ��λ���ϵ���
	for(int i = 0 ; i < n; i++){
		int t;
		cin>>t;
		if(t == i && t ) left--;
		v[t] = i ;//t��λ�� ��i
	}
	//1.ֻ���ƶ�0
	//2.�����ƶ����� ��ʹ������
	int ans = 0 ;
	int k = 1;
	while(left > 0 ){ 
		if(v[0] == 0 ){
			for(; k < n ; k++ ){
				if(v[k] != k ){
					swap(v[0],v[k]);//�ҵ�һ������λ���ϵ�����֮����
					ans++;
					break;
				}
			}
		}
		while(v[0] != 0 ){
			swap(v[0],v[v[0]]);//0ռ����v[0](������0)��λ�� ��֮����
			ans++;
			left--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
/**
1 2 0 3 4
*/
