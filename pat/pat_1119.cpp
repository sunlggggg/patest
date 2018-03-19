#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn =  32;
int n;
int pre[maxn];
int in[maxn];
int post[maxn];
struct Node{
	Node(int _data){
		data = _data;
		left = right = NULL;
	}
	int data;
	Node *left;
	Node *right;
};

bool flag = true;//�Ƿ�Ψһ
// Ѱ������
// 1 2�����Ӹ��� 3���Һ��Ӹ��� 4 6 7 5
// 2 6 7 4 5 3���Һ��Ӹ��� 1
//����pre���Һ��ӣ�������Ϊ���Һ��ӣ���ֻ��һ�����ӽڵ�ʱ��Ҳ������Ϊ�����ӽڵ㣩�ĸ�
int _pos(int preL , int preH , int vl){
	for(int i = preL+1; i < preH ;i++){
		if(pre[i] == vl){
			return  i ;
		}
	}
}
//the reason of not unique tree is that only one child node we do not 
//know it is the left or right child 
Node* buildTree(int preL, int preH,int postL, int postH ){
	Node *node = NULL;
	if(preL < preH) {
		node = new Node(pre[preL]);
		if(postH - postL > 1){ //���ܴ��ڵ������ĸ�
			int chi = post[postH - 2 ]; 
			int pre_leftChi_root_indx = _pos(preL,preH,chi);
			if(chi == pre[preL+1]){//ֻ�Ǵ���������Һ��� 
				node->left = buildTree(preL+1,preH,postL,postH-1);//����Ϊ������	
				flag = false;
			}else{
				//pre_leftChi_root_indx - preL - 1 :���ӳ���
				node->left = buildTree(preL+1,pre_leftChi_root_indx,postL,postL+(pre_leftChi_root_indx - preL - 1 ));//������
				node->right = buildTree(pre_leftChi_root_indx,preH,postL+(pre_leftChi_root_indx - preL - 1 ),postH-1);//������
			}
		}
	}
	return node;
}

int cnt = 0 ; 
void inOrder(Node *node){
	if(node == NULL){
		return ;
	}else{
		inOrder(node->left);
		cout<<node->data;
		cnt++;
		if(cnt < n ){
			cout<<" ";
		}else{
			cout<<endl;
		}
		inOrder(node->right);
	}
}
int main(){

#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	cin>>n;
	for(int i =0  ; i < n ; i++){
		cin>>pre[i];
	}
	for(int i =  0; i < n ; i++){
		cin>>post[i];
	}
	Node *tree = buildTree(0,n,0,n);
	if(flag){
		cout<<"Yes"	<<endl;
	}else{
		cout<<"No" <<endl;
	}
	inOrder(tree);
	return 0;
}