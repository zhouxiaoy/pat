#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[1000];
//2-1.3 ɾ�����Ա���ֵΪx�������ռ临�Ӷ�Ϊo��1�� ʱ��Ϊ o��n�� 
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
	puts("������Ҫɾ��������");
	scanf("%d",&x);
	del_x(x);
	for(int i=0;i<n;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
