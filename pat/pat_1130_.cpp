#include<iostream>
#include<string>
#include<set>
using namespace std;
int n;
const int MAXN = 1010;
struct Node{
	string data;
	int left;
	int right;
};
Node tree[MAXN];
bool root[MAXN];
int findRoot(){
	for(int i = 1 ; i<= n ; i++){
		if(root[i] == false)
			return i;
	}
}
int _root;
void inOrder(int root){
	if(root != -1){
		if(root!=_root && (tree[root].left!=-1||tree[root].right != -1)){
			printf("(");
		}
		inOrder(tree[root].left);
		printf("%s",tree[root].data.c_str());
		inOrder(tree[root].right);
		if(root!=_root && (tree[root].left!=-1||tree[root].right != -1)){
			printf(")");
		}
	}
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
	int left;
	int right;
	char cs[12];
	for(int i = 1 ; i <= n ; i++ ){
		scanf("%s %d %d",&cs,&left,&right);
		root[left] = root[right] = true;
		tree[i].data = cs;
		tree[i].left = left;
		tree[i].right = right;
	}
	//root 
	_root = findRoot();
	//中序遍历 如何添加括号
	inOrder(_root);
	return 0;
}