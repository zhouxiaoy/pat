#include <iostream>
using namespace std;

void Insert(int *b,int &sum,int x){
	if(sum<=0)
	{
		b[sum]=x;
		sum++;
		return;
	}
	int low=0,high=sum-1,mid;
	
	while(low<=high){
		mid=(high + low)/2;
		if(x<b[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	if(low>=sum){
		b[sum]=x;
		sum++;
	}
	else{
		if(x<b[low])
			b[low+1]=x;
		else
			b[low]=x;
	}
}

int LIS(int *a,int size){
	int *b = new int[size];
	int s=0;
	for(int i=0;i<size;i++){
		Insert(b,s,a[i]);
	}
	delete []b;
	return s;
}

int main()
{
	int a[]={5,6,7,1,2,6};
	int size = sizeof(a)/sizeof(int);
	int len = LIS(a,size);
	cout<<len<<endl; 
	return 0;
}
