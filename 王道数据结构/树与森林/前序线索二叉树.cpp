#include <iostream>
#include <cstdio>

using namespace std;

//Link 表示连接子结点，Thread是前后缀 
typedef enum { Link, Thread } pointerTag;

struct node {
	int data;
	node* left = NULL, *right = NULL;
	pointerTag lTag, rTag;
};

//平衡二叉树的插入 
node* insert(node* root, int x) {
	if (root == NULL) {
		root = new node();
		root->data = x;
		root->left = root->right = NULL;
		root->lTag = root->rTag = Link;
	}
	else {
		if (x < root->data)
			root->left = insert(root->left, x);
		else
			root->right = insert(root->right, x);
	}
	return root;
}

node * pre = NULL;
void preThread(node* root) {
	if (root != NULL) {
		if(root->left == NULL){
			root->lTag = Thread;
			root->left = pre;
			pre = root;
		}
		//更新pre的后缀
		if(pre != NULL && pre->right == NULL){
			pre->right = root;
			pre->rTag = thread;
		} 
		pre = root;
		if(root->lTag == Link)
			preThread(root->left);
		if(root->rTag == Link) 
			preThread(root->right);
	}
}

// 线索化
void createPreThread(node * root) {
	if (root != NULL) {
		preThread(root);
		pre->right = NULL;
		pre->rTag = Thread;
	}
}

//找到中序遍历的首结点
node* firstNode(node* root) {
	node* p = root;
	//如果lTag为0 循环到中序遍历的第一个结点
	while (p->lTag == Link) {
		p = p->left;
	}
	return p;
}

//找到中序遍历的后缀结点
node* nextNode(node* root) {
	if (root->rTag == Thread) return root->right;
	else return firstNode(root->right);
}

//找到中序遍历的尾结点(最后一个结点)
node *rearNode(node* root) {
	node* p = root;
	while (p->rTag == Link) //右子树存在
			p = p->right;
	return p;
}

//找中序遍历的结点前一个结点
node* preNode(node* root) {
	if (root->lTag == Thread) return root->left;
	else return rearNode(root->left);
}

void inOrder(node* root) {
	for (auto p = firstNode(root); p != NULL; p = nextNode(p))
		printf("%d ",p->data);
	puts("");
}

int main() {
	int n;
	node* root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		root = insert(root, a);
	}

	createInThread(root);
	cout << "前缀为:" << preNode(root->right)->data<<endl;
	cout<<"尾结点为:"<<rearNode(root)->data<<endl;
	inOrder(root);
	return 0;
}
