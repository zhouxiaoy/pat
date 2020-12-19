#include <iostream>
#include <cstring> 
using namespace std;

const int N = 1e5+5;
//分别代表  头结点  结点value，结点next 
int head,e[N],ne[N],idx;

//链表初始化 
void init(){
	head = -1;//-1代表为空 
	idx = 0;
}
//在头结点之后插入 
void insert_to_head(int x){
	e[idx] = x;//创建一个新结点value为x
	ne[idx] = head;//新节点指向head所指的位置 
	head = idx++;
}
//在第k个结点后插入 
void insert_to_knode(int x,int k){
	e[idx] = x;//创建一个新结点value为x
	ne[idx] = ne[k];//新节点指向第k个结点所指的位置
	ne[k] = idx++;
}
//删除第k个结点 
void delete_knode(int k){
	ne[k] = ne[ne[k]]; 
} 

//打印链表
void print(){
	int t = head;
	while(t!=-1){
		cout<<e[t]<<' ';
		t = ne[t];
	}
} 

int main(){
	int n;
	cin>>n;
	init();
	for(int i=0;i<n;i++){
		char ch;
		int a,b;
		cin>>ch;
		if(ch == 'H'){//头结点插入 
			cin>>b;
			insert_to_head(b);
		}else if(ch == 'I'){//第k个结点后插入 
			cin>>a>>b;
			insert_to_knode(b,a-1);
		}else{
			cin>>a;
			if(a)
				delete_knode(a-1);
			else//a等于0时，代表删除头结点 
				head = ne[head];//删除头结点是一个特例 
		}
	}
	print();	
	return 0;
} 
