#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
using namespace std;
const int maxn = 35;
int post[maxn];
int in[maxn];
struct Node {
	Node(int _data){
		data = _data;
	}
	int data;
	Node *left ;
	Node *right ; 
};
vector<Node*> ans[maxn];

int mpos(int inL, int inH , int vl ){
	for(int i = inL; i < inH ; i++){
		if(in[i] == vl)
			return i;
	}
}
Node * buildTree(int inL, int inH ,int postL , int postH){
	Node *node = NULL;
	//1 2 3 4
	//3 1 2 4
	if(inL<inH){
		node = new Node(post[postH - 1]);
		int pos = mpos(inL, inH ,node->data);
		node->left = buildTree(inL,pos,postL, postL+(pos-inL));
		node->right = buildTree(pos+1,inH , postL+(pos - inL),postH - 1);
	}
	return node;
}
int n;
int num = 0 ;
void print(Node *node){
	if(node == NULL)
		return;
	cout<<node->data;
	if(num != n -1){
		cout<<" ";
	}else{
		cout<<endl;
	}
	num++;
}
void ZigZagging(Node * root){
	queue<pair<Node *,int>> q;
	q.push(make_pair(root,0));
	int maxl;
	while(q.size()){
		Node *node = q.front().first;
		int lev  = q.front().second;
		maxl = lev;
		if(lev%2 == 0){
			ans[lev].insert(ans[lev].begin(),node);
		}else{
			ans[lev].push_back(node);
		}
		if(node->left){
			q.push(make_pair(node->left,lev+1));
		}
		if(node->right){
			q.push(make_pair(node->right,lev+1));
		}
		q.pop();
	}
	for(int i = 0 ; i <= maxl;i++ ){
		for(int k = 0 ; k < ans[i].size() ; k++){
			print(ans[i][k]);
		}
	}
}

int main(){
#ifdef _DEBUG
	freopen("1.txt","r",stdin);
#endif
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>in[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>post[i];
	}
	Node *node  = buildTree(0,n,0,n);
	ZigZagging(node);
	return 0;
}