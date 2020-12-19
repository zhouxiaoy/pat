#include <iostream>
#include <cstdio>

using namespace std;

//Link ��ʾ�����ӽ�㣬Thread��ǰ��׺ 
typedef enum { Link, Thread } pointerTag;

struct node {
	int data;
	node* left = NULL, *right = NULL;
	pointerTag lTag,rTag;
};

node* ni;

//ƽ��������Ĳ��� 
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
		if (root->left == NULL) {//������Ϊ�� 
			root->lTag = Thread;
			root->left = pre;
		}

		//�����һ�����ҽڵ�Ϊ�գ�Ҫ����� 
		if (pre != NULL && pre->right == NULL) {
			pre->rTag = Thread;
			pre->right = root;
		}

		pre = root;
		inThread(root->right);
	}
}

// ������
void createInThread(node * root) {
	if (root != NULL) {
		inThread(root);
		pre->right = NULL;
		pre->rTag = Thread;
	}
}

//�ҵ�����������׽��
node* firstNode(node* root) {
	node* p = root;
	//���lTagΪ0 ѭ������������ĵ�һ�����
	while (p->lTag == Link) {
		p = p->left;
	}
	return p;
}

//�ҵ���������ĺ�׺���
node* nextNode(node* root) {
	if (root->rTag == Thread) return root->right;
	else return firstNode(root->right);
}

//�ҵ����������β���(���һ�����)
node *rearNode(node* root) {
	node* p = root;
	while (p->rTag == Link) //����������
			p = p->right;
	return p;
}

//����������Ľ��ǰһ�����
node* preNode(node* root) {
	if (root->lTag == Thread) return root->left;
	else return rearNode(root->left);
}

void inOrder(node* root) {
	for (node* p = firstNode(root); p != NULL; p = nextNode(p))
		printf("%d ",p->data);
	puts("");
}

//�ҵ���������������ָ�����ĺ������ʱ��ǰ����� 
node* searchPost_pre(node* root){
	//�������� 
	if(root->rTag == Link) return root->right;
	//�������� 
	if(root->lTag == Link) return root->left;
	
	//ΪҶ�ӽ��
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
	cout << "ǰ׺Ϊ:" << preNode(root->right)->data<<endl;
	cout<<"β���Ϊ:"<<rearNode(root)->data<<endl;
	inOrder(root);
	cout<<"�ں����е�ǰ�����Ϊ:"<<searchPost_pre(ni)->data<<endl;
	return 0;
}
