#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.3 删除线性表中值为x的数，空间复杂度为o（1） 时间为 o（n） 
void del_nebor_same(){
	int k = 1;
	for(int i=1;i<n;i++){
		if(num[i-1]!=num[i]){
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
	del_nebor_same();
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
