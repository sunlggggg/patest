/**
1091. Acute Stroke (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.


Figure 1
Output Specification:

For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
**/
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Node{
	Node(){}
	Node(int _x,int _y , int _z){
		x = _x ; 
		y = _y;
		z = _z;
	}
	int x; int y ; int z ;
};
int m,n,h,v;
int pixel[1287][129][61];//脑切片
bool isAdd[1287][129][61] = {false};///表示已经入队
bool isNeedVis(int x, int y , int z ){
	if(x>=0&&x<n&&y>=0&&y<m &&z>=0&&z<h&&pixel[x][y][z] == 1 && isAdd[x][y][z] == false){
		return true;
	}else {
		return false;
	}
}
//用以下三个数组来进行上下左右前后的遍历 x是行 y是列 z是高
int X[6] = {0,0,0,0,1,-1};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {1,-1,0,0,0,0};
int BFS(int x, int y , int z ){
	int tot = 0;
	queue<Node> q;
	q.push(Node(x,y,z));
	isAdd[x][y][z] = true;//表示访问过了
	while(q.size()){
		Node node = q.front();
		q.pop();
		tot++;
		for(int i = 0 ; i < 6;i++){
			int newX = node.x + X[i];
			int newY = node.y+ Y[i];
			int newZ = node.z +Z[i];
			if(isNeedVis(newX,newY,newZ)){
				q.push(Node(newX,newY,newZ));
				isAdd[newX][newY][newZ] = true;//表示已经入队
			}
		}
	}
	if(tot >= v) 
		return tot;
	else 
		return 0;
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
	scanf("%d%d%d%d",&m,&n,&h,&v);//1296 
	int vl;
	for(int z = 0 ; z < h ; z ++){
		for(int y = 0 ; y < m ; y++){
			for(int x = 0 ; x < n ; x++){
				scanf("%d",&vl);
				pixel[x][y][z] = vl;
			}
		}
	}
	int ans = 0 ;
	for(int z = 0 ; z < h ; z ++){
		for(int y = 0 ; y < m ; y++){
			for(int x = 0 ; x < n ; x++){
				//当前位置未被访问
				if(pixel[x][y][z] == 1 && isAdd[x][y][z] == false  ){
					ans+=BFS(x,y,z);//深度遍历
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}