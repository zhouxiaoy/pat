//ɾ����������ֵΪx�Ľ�� 
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

node* del(node* root, int x) {
	node* q, *p;
	if (root == NULL)return NULL;

	/*��ɾ���׽�� ʧ�ܣ�Ҳ����Ϊû��root���ػ�ȥ�� 
	//ɾ���׽��Ϊx
	while(root != NULL && root->data == x){
		p = root;
		root = root->next;
		delete(p);
	}
	q = root;
	*/

	//��rootǰ��һ�����
	q = new node();
	q->next = root;
	node* preNode = q;//���һ�� ���ǵ�ɾ�� 

	while (q->next != NULL) {
		if (q->next->data == x) {
			p = q->next;
			q->next = q->next->next;
			delete(p);
		}
		else {
			q = q->next;
		}
	}
	root = preNode->next;
	delete(preNode);
	//��������Ϊ ָ�뱾����ֵ���ݣ������root������Ĳ�һ�� 
	return root;
}

int main() {
	node* root = NULL;
	int n;
	cin >> n;
	/*
	//�������� ͷ����
	for(int i=0;i<n;i++){
		node*q = new node();
		cin>>q->data;
		q->next = root;
		root = q;
	}
	*/

	//���ݲ��� β����
	node* rear = root;//β��� 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		if (root == NULL) root = q;
		else
			rear->next = q;
		rear = q;
	}

	int x;
	cout << "������Ҫɾ��������:";
	cin >> x;
	root = del(root, x);

	//��ӡ
	node* p = root;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	return 0;
}
