#include<iostream>
#include <cstring>
using namespace std;
int n;
int fun(int * a)
{
	int begin=0,end=n-1;
	if(a[begin]<a[end])return a[begin];
	while(begin+1<end)
	{
		int mid=begin+((end-begin)>>1);
		if(a[mid]>=a[begin])
			begin=mid;
		else
			end=mid;
	}
	return a[end];
}
int main()
{
	int str[100];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>str[i];
	cout<<fun(str);
	return 0;
} 
