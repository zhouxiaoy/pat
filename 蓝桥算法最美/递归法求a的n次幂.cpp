#include <stdio.h>

int pow(int a,int n){
	if(n==0)return 1;
	int res =a;
	int len =1;
	while((len<<1)<=n){
		res=res*res;
		len=len<<1; 
	}
	return res*pow(a,n-len); 
}
int main(){
	int n;
	printf("%d",pow(3,3));
	return 0;
} 
