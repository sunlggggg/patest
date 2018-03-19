#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct Node {
	Node(int _data){
		data = _data;
		left = right = NULL;
	}
	int data;
	Node *left;
	Node *right ;
};
void _insert(Node *&node,int vl){
	if(node == NULL){
		node = new Node(vl);
	}else if(vl > node->data){
		_insert(node->right , vl);
	}else{
		_insert(node->left,vl);
	}
}
int hei;
int low1,low2;
int low1n,low2n;
int  getHeight(Node *node){
	if(node == NULL){
		return 0;
	}else{
		return max(getHeight(node->left),getHeight(node->right)) + 1;
	}
}
void _count(Node *node,int level){
	if(node == NULL){
		return ;
	}else{
		if(level == low1){
			low1n++;
		}else if(level == low2){
			low2n++;
		}
		_count(node->left,level+1);
		_count(node->right,level+1);
	}
}


int main(){
	int n;
	cin>>n;
	Node *root = NULL;
	for(int i=0; i < n ;i++){
		int data;
		cin>>data;
		_insert(root,data);
	}
	hei = getHeight(root);
	low1 = hei;
	low2 = hei - 1;
	_count(root,1);
	cout<<low1n<<" + " <<low2n<<" = "<<(low1n+low2n)<<endl;
	return 0;
}