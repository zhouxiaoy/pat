#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;
int main()
{
	int i,j;
	int num[100];
	int a[105];
	for(i=1;i<=100;i++)a[i]=i;
	for(i=2;i<=100;i++)
	for(j=i+1;j<=100;j++){
		if(a[j]%a[i]==0)
			a[j]=a[j]/a[i];
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(num,0,sizeof(num));
		num[0]=1;
		for(i=2;i<=n;i++){
			int c=0;
			for(j=0;j<i;j++){
			int s=num[j]*a[i]+c;
			num[j]=s%10;
			c=s/10;
			}
		}
		for(i=99;i>=0;i--)
		if(num[i])break;
		for(j=i;j>=0;j--)
			printf("%d",num[j]);
		printf("\n");
	}
	return 0;
}
