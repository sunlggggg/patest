/**
1128. N Queens Puzzle (20)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The "eight queens puzzle" is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general N queens problem of placing N non-attacking queens on an N×N chessboard. (From Wikipedia - "Eight queens puzzle".)

Here you are NOT asked to solve the puzzles. Instead, you are supposed to judge whether or not a given configuration of the chessboard is a solution. To simplify the representation of a chessboard, let us assume that no two queens will be placed in the same column. Then a configuration can be represented by a simple integer sequence (Q1, Q2, ..., QN), where Qi is the row number of the queen in the i-th column. For example, Figure 1 can be represented by (4, 6, 8, 2, 7, 1, 3, 5) and it is indeed a solution to the 8 queens puzzle; while Figure 2 can be represented by (4, 6, 7, 2, 8, 1, 9, 5, 3) and is NOT a 9 queens' solution.




Figure 1

Figure 2
Input Specification:

Each input file contains several test cases. The first line gives an integer K (1 < K <= 200). Then K lines follow, each gives a configuration in the format "N Q1 Q2 ... QN", where 4 <= N <= 1000 and it is guaranteed that 1 <= Qi <= N for all i=1, ..., N. The numbers are separated by spaces.

Output Specification:

For each configuration, if it is a solution to the N queens problem, print "YES" in a line; or "NO" if not.

Sample Input:
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
Sample Output:
YES
NO
NO
YES
**/
#include<iostream>
#include<string>
#include<set>
using namespace std;
int n;
const int MAXN = 1010;
int arr[MAXN];

bool judgeRow(int c){
	set<int> _set;
	for(int i = 1; i <= c; i++){
		_set.insert(arr[i]);
	}
	if(_set.size() == c ){
		return true;
	}else {
		return false;
	}
}

//左上 左下 右上 右下 四个方向
int _x[4] = {1,1,-1,-1};
int _y[4] = {1,-1,1,-1};
bool inMap(int x , int y , int c){
	if(x>=1 && x<=c && y>=1 && y <=c ){
		return true;
	}else{
		return false;
	}
}
bool judgeDiagonal(int x, int y , int c){
	bool rt = true;
	int _tx = x;
	int _ty = y ;
	while(true){
		//left up 
		int newX, newY ;
		newX = x+_x[0];
		newY = y+_y[0];
		if(inMap(newX,newY,c) ){//左上存在
			if(arr[newX] == newY){
				rt = false;
				break;
			}else{
				x = newX;
				y = newY;
			}
		}else{
			break;
		}
	}
	if(rt){
		x = _tx;
		y = _ty;
		while(true){
			//left up 
			int newX, newY ;
			newX = x+_x[1];
			newY = y+_y[1];
			if(inMap(newX,newY,c) ){
				if(arr[newX] == newY){
					rt = false;
					break;
				}else{
					x = newX;
					y = newY;
				}
			}else{
				break;
			}
		}
	}
	if(rt){
		x = _tx;
		y = _ty;
		while(true){
			//left up 
			int newX, newY ;
			newX = x+_x[2];
			newY = y+_y[2];
			if(inMap(newX,newY,c) ){
				if(arr[newX] == newY){
					rt = false;
					break;
				}else{
					x = newX;
					y = newY;
				}
			}else{
				break;
			}
		}
	}
	if(rt){
		x = _tx;
		y = _ty;
		while(true){
			//left up 
			int newX, newY ;
			newX = x+_x[3];
			newY = y+_y[3];
			if(inMap(newX,newY,c) ){
				if(arr[newX] == newY){
					rt = false;
					break;
				}else{
					x = newX;
					y = newY;
				}
			}else{
				break;
			}
		}
	}
	return rt;
}

bool judge(int c ){
	//判断同列
	if(judgeRow(c) == false){
		return false;
	}else{
		for(int i = 1; i<=c ; i++){
			//判断对角线
			if(judgeDiagonal(i,arr[i],c) == false)
				return false;
		}
	}
	return true;
}

int main(){
#ifdef _DEBUG
	char ch;
	string s = "data";
	scanf("%c",&ch);
	s.push_back(ch);
	s.append(".txt");
	freopen(s.c_str(),"r",stdin);
#endif
	scanf("%d",&n);
	int c ;
	for(int i = 1 ; i <= n ; i++ ){
		scanf("%d",&c);
		for(int k = 1 ;  k <= c; k++){
			scanf("%d",&arr[k]);
		}
		bool rt = judge(c);
			if(rt)
				printf("YES\n");
			else 
				printf("NO\n");
	}
	return 0;
}