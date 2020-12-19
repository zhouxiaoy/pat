#include<stdio.h> 
int fun(int a,int b)
{
	int t=0;
	int res1,res2;
	res1=a*b;
	res2=(a/10*100+b/10%10*10+a%10)*(b/100*10+b%100);
	if(res1==res2)
	t=1;
	return t; 
}
int main()
{
	int num;
	int i,j;
	int n=0;
	for(i=10;i<100;i++)
	{
		for(j=100;j<1000;j++)
		{
			if(fun(i,j)==1)
			{
				n++;
				printf("%d*%d=%d*%d\t",i,j,i/10*100+j/10%10*10+i%10
				,j/100*10+j%100);
			}
			
		}
	}
	printf("\n"); 
	printf("%d",n);
	return 0;
}
