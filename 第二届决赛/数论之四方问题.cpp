#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int fun(int n,int a[],int idx){
	if(n==0) return 1;//����ֽ����
	if(idx==4) return 0;//����ֽ�����Ѵﵽ4����
	for(int i=(int)sqrt(n);i>=1;i--){
		a[idx]=i;
		if(fun(n-i*i,a,idx+1))
		{
			return 1;
		}
	}
	return 0; 
}
int main(){
	for(;;){
		int num;
		int a[4]={0};
		printf("�����루1��10��֮�������:");
		scanf("%d",&num);
		int r=fun(num,a,0);
		printf("%d %d %d %d %d\n",r,a[0],a[1],a[2],a[3]);
	}
	return 0;
}
