#include <iostream>

using namespace std;

struct node {
	char data;
	node* next;
};
int sum1,sum2;//��������ĳ��� 
//�ҳ������ڵ�
node* search(node* str1,node* str2) {
	//�ó����ַ����ȱ�����������������һ���� 
	node* q = str1,*p = str2;
	while(sum1>sum2 && q != NULL){
		q = q->next;
		sum1--;
	}
	while(sum1<sum2 && p != NULL){
		p = p->next;
		sum2--;
	}
	
	//�ж��Ƿ�Ϊͬһ�����
	while(q != NULL && p != NULL && p != q){
		q = q->next;
		p = p->next;
	} 
	if(p == q)
	return p;
	else return NULL;
}
//���첻������ַһ���ģ����Ǵ��ԭ����������� 
int main() {
	node* str1 = new node();

	cin >> sum1;

	//���ݲ��� β����
	node* rear = str1;//β��� 
	for (int i = 0; i < sum1; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}
	node* str2 = new node();
	cin >> sum2;

	//���ݲ��� β����
	rear = str2;//β��� 
	for (int i = 0; i < sum2; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		rear->next = q;
		rear = q;
	}	
	
	rear = search(str1,str2)
	cout<<rear->data<<endl;
	return 0;
}
