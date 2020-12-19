#include <iostream>
#include <cstdio>
using namespace std;

int queue[1000];
bool flag = 0;//0�����ǿ� 
int front = -1,rear = -1;

void push(int x){
	if(flag == 0){
		flag = 1;
		front = rear = 0;
		queue[rear] = x;
	}else{
		
		if((rear + 1)%1000 == front)
			puts("����������");
		else{
			rear = (rear+1)%1000;
			queue[rear] = x;
		}
	}
	printf("rear = %d front = %d\n",rear,front);
}

int pop(){
	int t;
	if(flag == 0){
		puts("����Ϊ�գ�"); 
		return -1;
	}else{
		if((front+1)%1000 == rear){//���һ��Ԫ�س�ջ 
			flag = 0;
			t = queue[front];
			front = rear = -1;	
		}else{
			t = queue[front];
			front = (front + 1) %1000;
		} 
	}
	printf("rear = %d front = %d\n",rear,front);
	return t;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x == 1)//push
			push(y);
		else//printf�ǲ����ǴӺ���ǰ��ֵ��ӡ�����ԣ�front��pop����֮ǰ��ֵ 
			printf("pop = %d rear = %d front = %d\n",pop(),rear,front);
	}
	return 0;
} 
