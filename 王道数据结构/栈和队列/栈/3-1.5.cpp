#include <iostream>
#include <cstdio>
using namespace std;

int maxsize = 100; 
int stack[100];
int top1 = -1,top2 = maxsize;

void push1(int x){
	if(top1 + 1 >= top2){
		puts("Õ»ÒÑÂú");
		return; 
	}
	stack[++top1] = x;
}

void push2(int x){
	if(top1 + 1 >= top2){
		puts("Õ»ÒÑÂú");
		return; 
	}
	stack[--top2] = x;
}

int pop1(){
	if(top1>=0)
		return stack[top1--];
	else
		{
			puts("Õ»1ÒÑ¿Õ");
			return -1;
		}
}

int pop2(){
	if(top2<maxsize)
		return stack[top2++];
	else
		{
			puts("Õ»2ÒÑ¿Õ");
			return -1;
		}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(y == 1){
			if(z == 1)
				push1(x);
			else		
				push2(x);
		}
		else{
			if(z == 1)
				printf("pop1 %d\n",pop1());
			else
				printf("pop2 %d\n",pop2());
		} 
	}
	return 0;
}
 
