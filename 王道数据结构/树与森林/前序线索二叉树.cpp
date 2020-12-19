#include <iostream>
#include <cstdio>

using namespace std;

//Link ��ʾ�����ӽ�㣬Thread��ǰ��׺ 
typedef enum { Link, Thread } pointerTag;

struct node {
	int data;
	node* left = NULL, *right = NULL;
	pointerTag lTag, rTag;
};

//ƽ��������Ĳ��� 
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
		//����pre�ĺ�׺
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

// ������
void createPreThread(node * root) {
	if (root != NULL) {
		preThread(root);
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
	cout << "ǰ׺Ϊ:" << preNode(root->right)->data<<endl;
	cout<<"β���Ϊ:"<<rearNode(root)->data<<endl;
	inOrder(root);
	return 0;
}
