#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.3 删除线性表中值为x的数，空间复杂度为o（1） 时间为 o（n） 
void del_x(int x){
	int k = 0;
	for(int i=0;i<n;i++){
		if(num[i]!=x){
			num[k] = num[i];
			k++;
		}
	}
	n = k;
} 


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	} 
	int x;
	puts("请输入要删除的数字");
	scanf("%d",&x);
	del_x(x);
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
