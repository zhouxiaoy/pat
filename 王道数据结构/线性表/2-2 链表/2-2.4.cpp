//ɾ����������ֵΪx�Ľ�� 
#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

void del_min(node* root) {
	node* q;
	node* minPre = root,*minIdx = root->next;
	
	q = root; 
	while (q->next != NULL) {
		if (q->next->data < minIdx->data) {
			minPre = q;
			minIdx = q->next;
		}
		q = q->next;
	}
	minPre->next = minIdx->next;
	delete(minIdx);
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

	del_min(root);

	//��ӡ
	node* p = root->next;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	return 0;
}
