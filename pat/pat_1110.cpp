/**
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
**/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N = 30;
bool root[N] = {0};
int n;
struct Pair{
	int l;
	int r;
};
Pair pairs[N];
int findRoot(){
	for(int i  = 0 ; i < n ; i++) {
		if(root[pairs[i].l] != -1)
			root[pairs[i].l] = true;
		if(root[pairs[i].r] != -1)
			root[pairs[i].r] = true;
	}
	for(  int  j =  0 ; j < n ; j++){
		if(root[j] == false ){
			return j;
		}
	}
}
int flag =0;
int last;
queue<int> q;
void level(int node){
	q.push(node);
	while(q.size()){
		int front = q.front();
		if(front == -1){
			if(flag == 0 ){
				flag = 1;
			}
		}else{
			last = front;
			if(flag == 1 ){
				flag = 2 ;
			}
			if(pairs[front].l < n && pairs[front].l >= -1)
				q.push(pairs[front].l);
			if(pairs[front].r < n && pairs[front].r >= -1)
				q.push(pairs[front].r);
		}
		q.pop();
	}
}
using namespace std;
int main(){
	cin>>n;
	char c1, c2;
	for(int i = 0 ; i< n ; i++){
		cin>>c1>>c2;
		Pair pair ;
		if(c1 == '-'){
			pair.l = -1;
		}else{
			pair.l = c1-'0';
		}
		if(c2 == '-'){
			pair.r = -1;
		}else{
			pair.r = c2-'0';
		}
		pairs[i] = pair;
	}
	int rootId = findRoot();
	level(rootId);
	if(flag < 2){
		cout<<"YES "<<last<<endl;
	}
	else 
		cout<<"NO "<<rootId<<endl;
	return 0;
}