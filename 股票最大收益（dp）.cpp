#include <iostream>
using namespace std;
int MaxProfit(const int *a,int size){
	int p=0;
	int mn=a[0];
	for(int i=1;i<size;i++){
		mn=min(mn,a[i-1]);
		p=max(p,a[i]-mn);
	}
	return p;
}
int main(){
	int a[]={7,1,5,3,6,4};
	cout<<MaxProfit(a,sizeof(a)/sizeof(int));
}
