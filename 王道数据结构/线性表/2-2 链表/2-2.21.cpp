#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

//�ҵ�������k���� 
int find_K(node* root,int k){
	if(root == NULL)return 0;
	node* pre = root->next,* p = root->next;
	int ans = 1;
	while(p && ans < k){
		p = p->next;
		ans++;
	}
	//������û��k�� 
	if(ans != k)return 0;
	
	while(p->next != NULL){
		pre = pre->next;
		p = p->next; 
	}
	cout<<pre->data<<endl;
	return 1;
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
	
	int x;
	cin>>x;
	find_K(root,x);
	return 0;
}
