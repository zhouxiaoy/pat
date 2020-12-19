#include <iostream>
#include <cstdio>
using namespace std;
int LocalMaximun(const int *a,int size){
	int left=0;
	int right=size-1;
	int mid;
	while(left<right)
	{
		mid=(left+right)/2;
		cout<<mid<<endl;
		if(a[mid]>a[mid+1])
			right=mid;
		else
			left=mid+1;
	}
	return a[left];
}
int Mode(int *a,int size){
	int count=0;
	int m;
	for(int i=0;i<size;i++){
		if(count==0){ 
			m=a[i];
			count++;
		}
		else if(m!=a[i])
		count--;
		else
		count++;
	}
	return m;
}
int main()
{
	int a[]={8,8,1,1,1,8,1,1,6,1,8};
	int m=Mode(a,sizeof(a)/sizeof(int));
	int n=LocalMaximun(a,sizeof(a)/sizeof(int));
	cout<<m<<' '<<n<<endl;
	return 0;
} 
