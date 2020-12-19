#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int data;
	node* next;
};

//�ж��Ƿ�Ϊѭ�������ǵĻ�������ڵ� 
node* fun(node* root){
	if(root == NULL) return NULL;
	node* p = root->next;
	while(p->next && p->next != root->next)
		p = p->next;
	if(p->next == NULL)return NULL;
	return root->next; 
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
		if(i != 0)
			q->next = root->next;
		else	q->next = root;
		rear->next = q;
		rear = q;
	}
	
	rear = fun(root);
	cout<<rear->data<<endl;
	return 0;
}
