#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num[100]={0},a[105]={0};
	
	for(int i=1;i<=n;i++)
		a[i]=i;
	//计算出从1到n的最小公约数 
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=101;j++){
			if(a[j]%a[i]==0)
				a[j]/=a[i];
		}
	}
	/*
	for(int i=1;i<=101;i++)
	{
		if(i%10==0)
			cout<<endl;
		cout<<a[i]<<' '; 
	} 
	*/
	num[0]=1;
	for(int i=2;i<=n;i++){
		int c=0;
		for(int j=0;j<i;j++){
			int s=num[j]*a[i]+c;
			num[j]=s%10;
			c=s/10;
		}
	}
	
	int i=99;
	while(i>=0&&num[i]==0) i--;
	
	for(int j=i;j>=0;j--){
		printf("%d",num[j]);
	}
	printf("\n");
	return 0;
} 
