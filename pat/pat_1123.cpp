#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
struct Node{
	Node(int _data){
		data = _data;
		left = right = NULL;
		hei = 1;
	}
	int data;
	int hei;
	Node *left;
	Node *right;
};
int updataHei(Node *root){
	int lH = root->left!=NULL?root->left->hei:0;
	int rH = root->right!=NULL?root->right->hei:0;
	root->hei =  max(lH,rH)+1;
	return root->hei;
}
//右旋
//    A               B
//  B    --->      C      A 
//C   X                 X
void R(Node *&root){
	Node *A = root;
	Node *B = root->left ; 
	Node *X = B->right;
	B->right = A;
	A->left = X;
	updataHei(A);
	root = B;
	updataHei(root);
}
//左旋
// A               B
//   B   ---->  A      C
//  X  C           X
void L(Node *&root){
	Node *A = root;
	Node *B = root->right ; 
	Node *X = B->left;
	B->left = A;
	A->right = X;
	updataHei(A);
	root = B;
	updataHei(root);
}

//计算平衡因子
int cmpBf(Node *root){
	int lBf = root->left!=NULL?root->left->hei:0;
	int rBf = root->right!=NULL?root->right->hei:0;
	return lBf - rBf;
}
void _insert(Node *&root,int data){
	if(root== NULL){
		root = new Node(data);
	}else if(data < root->data){//插入左子树
		_insert(root->left,data);
		updataHei(root);//更新高度
		if(cmpBf(root) == 2){ //左子树高度大
			if(cmpBf(root->left) == 1){ //LL 
				//右旋
				R(root);
			}else { //LR
				//左旋
				L(root->left);
				//右旋
				R(root);
			}
		}
	}else{//插入右子树
		_insert(root->right,data);
		updataHei(root);//更新高度
		if(cmpBf(root) == -2){ //右子树高度大
			if(cmpBf(root->right) == -1){ //RR
				//左旋
				L(root);
			}else { //RL
				//右旋
				R(root->right);
				//左旋
				L(root);
			}
		}
	}
}

int n;
int flag = 0 ;
void levelOrder(Node *root){
	queue<Node*> q;
	q.push(root);
	int num = 0 ;
	while(q.size() > 0 ){
		Node *front = q.front();
		cout<<front->data ;
		if(num < n -1){
			cout << " ";
		}else{
			cout << endl;
		}
		if(front->left){
			q.push(front->left);
			if(flag == 1){//前面存在非空子节点
				flag = 2;
			}
		}else if(flag == 0 ){
			flag = 1;
		}
		if(front->right){ 
			q.push(front->right);
			if(flag == 1){
				flag  = 2;
			}
		}else if(flag == 0 ){
			flag = 1;
		}
		q.pop();
		num++;
	}
}
int main(){
	cin>>n;
	Node *root=NULL;
	for(int i = 0 ; i< n ; i++){
		int data;
		//8
		//88 70 61 96 120 90 65 68
		cin>>data;
		_insert(root,data);
	}
	levelOrder(root);
	if(flag != 2){
		cout<<"YES"<<endl;
	}else {
		cout<<"NO"<<endl;
	}
	return 0 ; 
}