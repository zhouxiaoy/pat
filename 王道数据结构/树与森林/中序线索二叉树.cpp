#include <iostream>
#include <cstdio>

using namespace std;

//Link 表示连接子结点，Thread是前后缀 
typedef enum { Link, Thread } pointerTag;

struct node {
	int data;
	node* left = NULL, *right = NULL;
	pointerTag lTag,rTag;
};

node* ni;

//平衡二叉树的插入 
node* insert(node* root, int x) {
	if (root == NULL) {
		root = new node();
		root->data = x;
		root->left = root->right = NULL;
		root->lTag = root->rTag = Link;
		if(x == 9)ni = root;
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
void inThread(node* root) {
	if (root != NULL) {
		inThread(root->left);
		if (root->left == NULL) {//左子树为空 
			root->lTag = Thread;
			root->left = pre;
		}

		//如果上一个的右节点为空，要连后继 
		if (pre != NULL && pre->right == NULL) {
			pre->rTag = Thread;
			pre->right = root;
		}

		pre = root;
		inThread(root->right);
	}
}

// 线索化
void createInThread(node * root) {
	if (root != NULL) {
		inThread(root);
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
	for (node* p = firstNode(root); p != NULL; p = nextNode(p))
		printf("%d ",p->data);
	puts("");
}

//找到中序线索二叉树指定结点的后序遍历时的前驱结点 
node* searchPost_pre(node* root){
	//有右子树 
	if(root->rTag == Link) return root->right;
	//有左子树 
	if(root->lTag == Link) return root->left;
	
	//为叶子结点
	while(root && root->lTag == Thread)
		root = root->left;
	if(root) return root->left;
	else return NULL;
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
	cout<<"在后序中的前驱结点为:"<<searchPost_pre(ni)->data<<endl;
	return 0;
}
