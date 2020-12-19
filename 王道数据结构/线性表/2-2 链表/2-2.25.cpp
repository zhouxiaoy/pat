#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* next;
};

//�ҵ�������м��� 
node* fun(node* root) {
	if (root == NULL) return NULL;
	node* p = root, *q = root;
	//����Ҫ��q->next �����ֽ�����������Ϊ�������ֻʣһ���� 
	while (q->next != NULL && q->next->next != NULL)
	{
		p = p->next;
		q = q->next->next;
	}
	if (q->next != NULL)p = p->next;
	return p;
}

void fun2(node *root){
	node* p = fun(root);//ǰ��ε�β��� 
	node* q = p->next;//���ε��׽�� 
	node* r,*s; 
	p->next = NULL;
	while(q!=NULL){//�����η�ת 
		r= q->next;
		r->next = q;
	} 
} 

int main() {
	node* root = new node();
	int n;
	cin >> n;

	//���ݲ��� β����
	node* rear = root;//β��� 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}

	rear = fun(root);
	cout << rear->data << endl;
	return 0;
}
