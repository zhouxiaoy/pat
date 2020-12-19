#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct AVLnode {
	int height;
	int val;
	AVLnode* left;
	AVLnode* right;
}AVL;

int n;

bool isCBT = true;//Ĭ������ȫ��������complete binary tree�� 
//avlģ��
int height(AVL* root) {
	if (root == NULL)return 0;
	return root->height;
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

//LR������� 
AVL* rotateLeftRight(AVL* root) {
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}

//RL���Һ��� 
AVL* rotateRightLeft(AVL* root) {
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}

//���뺯��
AVL* insert(AVL* root, int val) {
	if (root == NULL) {
		root = new AVL();
		root->val = val;
		root->right = root->left = NULL;
	}
	else if (val > root->val) {//�������� 
		root->right = insert(root->right, val);
		if (height(root->left) - height(root->right) == -2)
			root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
	}
	else {
		root->left = insert(root->left, val);
		if (height(root->left) - height(root->right) == 2)
			root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
	}
	//���¸߶� 
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

int main() {
	int num;
	scanf("%d", &n);
	AVL* root = NULL;
	for (int i = 0; i < n; i++) {	
		scanf("%d", &num);
		root = insert(root, num);
	}

	int sum = 0;
	vector<int> v;
	queue<AVL*> q;
	q.push(root);
	while (q.size()) {
		AVL* t = q.front();
		q.pop();
		if (t != NULL) {
			v.push_back(t->val);
			sum++;
			q.push(t->left);
			q.push(t->right);
		}
		else {
			if (sum != n)isCBT = false;
		}
	}
	printf("%d", v[0]);
	for (int i = 1; i < v.size(); i++)
		printf(" %d", v[i]);
	if (!isCBT)
		puts("\nNO");
	else
		puts("\nYES");
	return 0;
}
