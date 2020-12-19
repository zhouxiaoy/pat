	//为什么一定要是max（l，r）呢 

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

//enum {red,black};
struct RBT{
	//enum color;
	RBT* left,*right;
	int data;
};

RBT* insert(RBT* root,int x){
	if(root == NULL){
		root = new RBT();
		root->data = x;
		root->left = root->right = NULL;
	}else{
		if(abs(x) <= abs(root->data))
			root->left = insert(root->left,x);
		else
			root->right = insert(root->right,x);
	}
	return root;
}

//判断红节点的孩子结点是否都为黑 
bool f1(RBT* root){
	if(root == NULL)return true; 
	if(root->data<0){
		if(root->left != NULL && root->left->data < 0)return false;
		if(root->right != NULL && root->right->data <0)return false;
	}
	return f1(root->left) && f1(root->right); 
}

int getNum(RBT* root){
	if(root == NULL) return 0;
	int l = getNum(root->left);
	int r = getNum(root->right);
	//为什么一定要是max（l，r）呢 
	return root->data > 0 ? max(l,r)+1 : max(l,r);
}

bool f2(RBT* root){
	if(root == NULL) return true;
	int l = getNum(root->left);
	int r = getNum(root->right);
	if(l != r) return false;
	return f2(root->left) && f2(root->right); 
}

int main(){
	int n;
	scanf("%d",&n);
	while(n --){
		int k,a;
		scanf("%d",&k);
		RBT* root = NULL;
		for(int i=0;i<k;i++){
			scanf("%d",&a);
			root = insert(root,a);
		}
		
		bool flag = f1(root) && f2(root);
		if(root->data <0 ||flag == false)  puts("No");
		else puts("Yes");
	}
	return 0;
} 
