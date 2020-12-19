#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.1删除顺序表中最小值 
int getMin() {
	int min = 0;
	for(int i=1;i<n;i++){
		if(num[i]<num[min])min = i;
	}
	int t = num[min];
	for(int i=min;i<n-1;i++){
		num[i] = num[i+1];
	}
	n--;
	return t;
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	printf("%d\n",getMin());
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
