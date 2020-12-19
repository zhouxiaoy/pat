#include <iostream>
using namespace std;
int pow(int a,int n){
	if(n==0)return 1;
	int res = a;
	int idx = 1;
	while((idx<<2)<=n){
		res*=res;
		idx<<=1;
	}
	return res*pow(a,n-idx);
}
int main(){
	int n;
	int a;
	cin>>a>>n;
	cout<<pow(a,n); 
	return 0;
}
