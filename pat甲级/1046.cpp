#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010];
int b[200010];//�洢��1-i��·��֮�� 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i] + b[i-1];
	}
	for(int i=n+1;i<=2*n;i++){
		a[i]=a[i-n];//�������������ͬ��������������ģ��������� 
		b[i] = a[i] + b[i-1];
	}
	int m,x,y;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		if(y<x)y+=n;
		int t = b[y-1]-b[x-1];//�����ߵ�·��ֵ 
		printf("%d\n",min(b[n]-t,t));//��Ϊ�����ߺʹ�����֮���ǹ̶��ģ�ֻҪ�ж��Ǳߵ�С���� 
	} 
	return 0;
} 
