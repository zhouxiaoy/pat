#include <iostream>
using namespace std;

int MaxProfit(const int * a,int size){
	int p=0;
	int mn=a[0];
	for(int i=0;i<size;i++){
		mn=min(mn,a[i]);
		p = max(p,a[i]-mn);
	}
	return p;
}

int main()
{
	int a[]={1};
	cout<<MaxProfit(a,sizeof(a)/sizeof(int))<<endl;
	return 0;
} 
