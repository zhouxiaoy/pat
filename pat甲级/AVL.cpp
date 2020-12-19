#include <iostream>
#include <cmath>
#include <cstdio> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct AVLTree {
	int value;//ֵ
	int height;//�߶� 
	AVLTree* left;//������ 
	AVLTree* right; //������ 
} AVL;

//�߶�
int height(AVL* root) {
	if (root != NULL)
		return root->height;
	else return 0;
}

//RR����ת
AVL* rotateLeft(AVL* root) {
	AVL* t = root->right;
	root->right = t->left;
	t->left = root;
	//���¸߶� 
	root->height = max(height(root->left), height(root->right)) + 1;
	t->height = max(height(t->right), root->height) + 1;

	return t;
}

//LL����ת
AVL* rotateRight(AVL* root) {
	AVL* t = root->left;
	root->left = t->right;
	t->right = root;
	//���¸߶�
	root->height = max(height(root->left), height(root->right)) + 1;
	t->height = max(height(t->left), root->height) + 1;
	return t;
}

//LR������ת������ת
AVL* rotateLeftRight(AVL* root) {
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}

//RL������ת������ת 
AVL* rotateRightLeft(AVL* root) {
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}

//������ 
AVL* insert(AVL* root, int val) {
	if (root == NULL) {
		root = new AVL();
		root->value = val;
		root->left = root->right = NULL;
	}
	else if (val < root->value) {//���������� 
		root->left = insert(root->left, val);
		if (height(root->left) - height(root->right) == 2)//�ýڵ㲻ƽ�� 
			root = val < root->left->value ? rotateRight(root) : rotateLeftRight(root);
	}
	else {//����������
		root->right = insert(root->right, val);
		if (height(root->left) - height(root->right) == -2)
			root = val > root->right->value ? rotateLeft(root) : rotateRightLeft(root);
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

//ɾ�����
/*	3����� 
 *1. ɾ��Ҷ�ӽڵ�  ��ʧȥƽ��  �������������½ڵ�߶ȣ�δʧȥƽ�⣬ֻ���½ڵ�߶�
 *2. ɾ������һ���ӽڵ�Ľ��  ��ʧȥƽ�⣬�������������½��߶ȣ���δʧȥƽ�⣬ ֻ���½��߶�
 *3. ɾ�����������ӽڵ�Ľ�� 
*/
AVL* Del(AVL* root,int x){
	AVL* SNode = NULL,PSNode = NULL,temp = NULL;//��̽ڵ㣬��̽ڵ�ĸ��ڵ㣬��ʱ������ͷŽ������� 
	if(root == NULL){
		return NULL;//������ 
	}else if(x > root->val){
		root->right = Del(root->right,x);
		if(height(root->left) - height(root->right) == 2){
			temp = nod->left;
			if(height(temp->left) >= height(temp->right)){
				//LL ��LR
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
				//LL ��LR
				root = rotateRight(root); 
			}
			else{//RL 
				root = rotateRightLeft(root); 
			}
			root->height = max(height(root->left),height(root->right));
	}
		else{//�ҵ��� 
			if(root->right == NULL && root->left == NULL){
				free(nod);
				return NULL;
			} 
		}
	} 
	
} 

int main() {
	AVL* root = NULL;//���ڵ� 
	int n, val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("%d", root->value);
	
	return 0;
}
