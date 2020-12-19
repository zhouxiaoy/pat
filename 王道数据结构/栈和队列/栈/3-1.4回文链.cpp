#include <iostream>

using namespace std;

struct node {
	char data;
	node* next;
};

bool f(node* root,int n){
    int idx = 0;
    char nod[10000];
    node* q = root->next;
    while(q != NULL && idx < n/2) {
        printf("%c\n",q->data);
        nod[idx++] = q->data;
        q = q->next;
    }
    //printf("%c\n",q->data);
    puts("");
    if(n%2 == 1) q = q->next;
    while(q != NULL){
        printf("%c\n",q->data);
        if(nod[--idx] != q->data)
            return false;
        q = q->next;
    }
    return true;
}

int main() {
	node* root = new node();
	int n;
	cin >> n;

	//数据插入 尾插入
	node* rear = root;//尾结点 
	for (int i = 0; i < n; i++) {
		node* q = new node();
		cin >> q->data;
		q->next = NULL;
		
		rear->next = q;
		rear = q;
	}
	if(f(root,n))
	    puts("Yes");
	else
	    puts("No");
	
	return 0;
}
