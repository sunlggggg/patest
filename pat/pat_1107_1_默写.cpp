/**
1107. Social Clusters (30)
ʱ������
1000 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

Ki: hi[1] hi[2] ... hi[Ki]

where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
**/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int  n ; //��1-n
const int maxn = 1010;
int hobby[maxn] = {0}; //ĳ��ϲ����hobby���ˣ������޸�ΪȦ��ͷ��Ҳ����ͨ��ÿ��Ѱ�ң�
int father[maxn] = {0};//ĳ���˵���һ��
int peopel_count[maxn]= {0};//1-n 1�Ƿ���ͷ���Ҹ�Ȧ�������� ÿ��һ�����Ը�ȦΪͷ ++
void init(){
	for(int i = 1; i<= n ; i++){
		father[i] = i ;
	}
}
int findRoot(int x){
	
	int tmp = x;
	while(x!=father[x]){
		x = father[x];
	}
	//·��ѹ��
	while(tmp!=father[tmp]){
		int _tmp = father[tmp];
		father[tmp] = x;
		tmp = _tmp;
	}
	return x;
}
bool cmp(int a,int b){
	return a>b;
}
int main() {
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d",&n);
	int hb;
	int h ;
	init();
	for(int i = 1; i <= n ; i++){
		scanf("%d:",&hb); //�����
		for(int k = 0 ; k< hb ; k++){
			scanf("%d",&h);
			int rootI = findRoot(i);
			if(hobby[h] == 0 ){//��һ�α�ϲ��
				father[i] = rootI;
				hobby[h] = rootI;
			}else{
				int rootH = findRoot(hobby[h]);
				if(rootH!=rootI){
					father[rootH] = rootI;
					hobby[h] = rootI;
				}
			}
		}
	}

	for(int i = 1; i <= n ; i++){
		peopel_count[findRoot(i)]++;
	}

	sort(peopel_count+1,peopel_count+n+1,cmp);//�Ӵ�С����
	int c = 0;
	//ͳ��Ȧ�ĸ���
	for(int i = 1; i <= n ; i++){
		if(peopel_count[i] != 0){
			c++;
		}
	}
	printf("%d\n",c);
	for(int i = 1 ; i <= c ; i++){
		printf("%d", peopel_count[i]);
		if(i < c)
			printf(" ");
	}
	return 0;
}