#include<iostream>
#include<vector>
using namespace std;
int n;
const int maxn = 35;
struct Node{
	Node(int _data){
		data = _data;
	}
	int data;
	Node *left;
	Node *right;
};
int _pos(vector<int> in , int vl){
	for(int i = 0 ; i < in.size(); i++){
		if(in[i] == vl){
			return i;
		}
	}
} 
vector<int> _find(vector<int> level, vector<int> in){
	int Isfind[maxn] = {0};
	for(int i = 0 ; i < in.size() ; i++){
		for(int j = 0 ; j < level.size(); j++){
			if(level[j] == in[i]){
				Isfind[j] = true;
				break;
			}
		}
	}
	vector<int> v;
	for(int i = 0 ; i < level.size() ; i++){
		if(Isfind[i] ){
			v.push_back(level[i]);
		}
	}
	return v;
}
Node *buildTree(vector<int> in, vector<int> level){
	Node *node = NULL;
	if(in.size() > 0 ){
		node = new Node(level.at(0));
		//»®·Ö
		int pos = _pos(in,node->data);
		vector<int> inLeft(in.begin(),in.begin()+pos);
		vector<int> inRight(in.begin()+pos+1,in.end());
		vector<int> levelLeft = _find(level,inLeft);
		vector<int> levelRight = _find(level,inRight);
		node->left = buildTree(inLeft,levelLeft);
		node->right = buildTree(inRight,levelRight);
	}
	return node;
}
int cnt = 0 ;
void preOrder(Node *node){
	if(node == NULL){
		return;
	}else{
		cnt++;
		cout<<node->data;
		if(cnt < n ){
			cout<<" ";
		}else{
			cout<<endl;
		}
		preOrder(node->left);
		preOrder(node->right);
	}
}
void postOrder(Node *node){
	if(node == NULL){
		return;
	} else{
		postOrder(node->left);
		postOrder(node->right);
		cnt++;
		cout<<node->data;
		if(cnt < n ){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
}

int main(){

	cin>>n;
	vector<int> in , level;
	int num;
	for(int i = 0 ; i < n ;i++){
		cin>>num;
		level.push_back(num);
	}

	for(int i = 0 ; i < n ;i++){
		cin>>num;
		in.push_back(num);
	}
	Node * tree = buildTree(in,level);
	cnt = 0 ;
	preOrder(tree);
	cnt = 0;
	postOrder(tree);
	return 0;
}