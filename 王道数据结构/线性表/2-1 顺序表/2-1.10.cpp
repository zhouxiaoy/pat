#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.10
//·­×ªË³Ðò±í
void reverse(int l,int r){
	int t,length = r - l + 1;
	for(int i=0;i< length/2;i++){
		t = num[i+l];
		num[i+l] = num[r-i];
		num[r-i] = t;
	} 
}

void fun(int p){
	reverse(0,p-1);
	reverse(p,n-1);
	reverse(0,n-1);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	int p;
	puts("ÇëÊäÈëP£º");
	scanf("%d",&p);
	fun(p);
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
