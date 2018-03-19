/**
1090. Highest Price in Supply Chain (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2

**/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
const int maxn = 100010;
vector<int> childs[maxn];
long double ans = 0 ;
double p, r;
//dfs 计算深度
int maxDepth = 0 , num = 0 ;//最大深度和最大深度节点数目
void dfs(int root , int depth){
	if(childs[root].size() == 0 ){//叶子节点
		if(depth>maxDepth){
			maxDepth = depth;
			num = 1;
		}else if(depth == maxDepth){
			num++;
		}
		return ;
	}else {
		for(int i = 0 ; i < childs[root].size();i++){
			dfs(childs[root][i],depth+1);
		}
	}
}
int main() {
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%lf%lf",&p,&r);
	int father;
	int root;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&father);
		if(father == -1){
			root = i ;//当前的i没有父亲节点
		}
		childs[father].push_back(i);
	}
	dfs(root,0);
	printf("%.2f %d\n",p*pow(1+r/100.0,maxDepth),num);
	return 0;
}