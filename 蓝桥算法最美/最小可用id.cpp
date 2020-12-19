#include <iostream>
using namespace std;
int find(int a[],int n){
	int *b =new int[n+1];
	for(int i=1;i<=n;i++)
		b[i]=0;
	for(int i=0;i<n;i++){
		if(a[i]<n+1)
			b[a[i]] = 1;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0)
			return i;
	} 
	return n+1;
}
int main(){
	int a[]={3,2,15,6,7,2,1,6,23,4,43,4};
	cout<<find(a,12);
	return 0;
}
