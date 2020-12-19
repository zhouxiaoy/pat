#include <iostream>
#include <cstdio> 
using namespace std;
int MaxSubbrray(const int *a, int size)
{
	if(!a||(size<=0))
	return 0;
	int sum=a[0];
	int result=sum;
	for(int i=1;i<size;i++)
	{
		if(sum>0)sum+=a[i];
		else sum=a[i];
		result=max(sum,result);
	}
	return result;
}
int main()
{
	int a[]={1,-2,3,10,-4,7,2,-5};
	int m=MaxSubbrray(a,sizeof(a)/sizeof(int));
	cout<<m;
	return 0;
}
