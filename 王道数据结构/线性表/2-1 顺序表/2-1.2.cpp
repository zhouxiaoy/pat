#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.2��ת˳��� �ռ临�Ӷ�δ1 
void reverse(){
	int t;
	for(int i=0;i<n/2;i++){
		t = num[i];
		num[i] = num[n-1-i];
		num[n-1-i] = t;
	} 
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	reverse();
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
