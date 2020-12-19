#include <iostream>
#include <cmath>
#include <cstdio> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct AVLTree {
	int value;//值
	int height;//高度 
	AVLTree* left;//左子树 
	AVLTree* right; //右子树 
} AVL;

//高度
int height(AVL* root) {
	if (root != NULL)
		return root->height;
	else return 0;
}

//RR左旋转
AVL* rotateLeft(AVL* root) {
	AVL* t = root->right;
	root->right = t->left;
	t->left = root;
	//更新高度 
	root->height = max(height(root->left), height(root->right)) + 1;
	t->height = max(height(t->right), root->height) + 1;

	return t;
}

//LL右旋转
AVL* rotateRight(AVL* root) {
	AVL* t = root->left;
	root->left = t->right;
	t->right = root;
	//更新高度
	root->height = max(height(root->left), height(root->right)) + 1;
	t->height = max(height(t->left), root->height) + 1;
	return t;
}

//LR先左旋转再右旋转
AVL* rotateLeftRight(AVL* root) {
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}

//RL先右旋转再左旋转 
AVL* rotateRightLeft(AVL* root) {
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}

//插入结点 
AVL* insert(AVL* root, int val) {
	if (root == NULL) {
		root = new AVL();
		root->value = val;
		root->left = root->right = NULL;
	}
	else if (val < root->value) {//在左子树中 
		root->left = insert(root->left, val);
		if (height(root->left) - height(root->right) == 2)//该节点不平衡 
			root = val < root->left->value ? rotateRight(root) : rotateLeftRight(root);
	}
	else {//在右子树中
		root->right = insert(root->right, val);
		if (height(root->left) - height(root->right) == -2)
			root = val > root->right->value ? rotateLeft(root) : rotateRightLeft(root);
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

//删除结点
/*	3种情况 
 *1. 删除叶子节点  树失去平衡  调整树，并更新节点高度；未失去平衡，只更新节点高度
 *2. 删除带有一个子节点的结点  树失去平衡，调整树，并更新结点高度；树未失去平衡， 只更新结点高度
 *3. 删除带有两个子节点的结点 
*/
AVL* Del(AVL* root,int x){
	AVL* SNode = NULL,PSNode = NULL,temp = NULL;//后继节点，后继节点的父节点，临时保存带释放结点的子树 
	if(root == NULL){
		return NULL;//不存在 
	}else if(x > root->val){
		root->right = Del(root->right,x);
		if(height(root->left) - height(root->right) == 2){
			temp = nod->left;
			if(height(temp->left) >= height(temp->right)){
				//LL 或LR
				root = rotateRight(root); 
			}
			else{//RL 
				root = rotateRightLeft(root); 
			}
			root->height = max(height(root->left),height(root->right));
		}
	}
	else if(x < root->val){
		root->left = Del(root->left,x);
		if(height(root->left) - height(root->right) == -2){
			temp = nod->left;
			if(height(temp->left) >= height(temp->right)){
				//LL 或LR
				root = rotateRight(root); 
			}
			else{//RL 
				root = rotateRightLeft(root); 
			}
			root->height = max(height(root->left),height(root->right));
	}
		else{//找到了 
			if(root->right == NULL && root->left == NULL){
				free(nod);
				return NULL;
			} 
		}
	} 
	
} 

int main() {
	AVL* root = NULL;//根节点 
	int n, val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("%d", root->value);
	
	return 0;
}
