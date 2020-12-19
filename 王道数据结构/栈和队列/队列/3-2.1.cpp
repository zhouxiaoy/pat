#include <iostream>
#include <cstdio>
using namespace std;

int queue[1000];
bool flag = 0;//0代表是空 
int front = -1,rear = -1;

void push(int x){
	if(flag == 0){
		flag = 1;
		front = rear = 0;
		queue[rear] = x;
	}else{
		
		if((rear + 1)%1000 == front)
			puts("队列已满！");
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
		puts("队列为空！"); 
		return -1;
	}else{
		if((front+1)%1000 == rear){//最后一个元素出栈 
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
		else//printf是参数是从后往前赋值打印的所以，front是pop（）之前的值 
			printf("pop = %d rear = %d front = %d\n",pop(),rear,front);
	}
	return 0;
} 
