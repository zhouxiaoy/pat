#include <iostream>
#include <cstdio>
using namespace std;
int a[10] = {1,3,9,27,81};
void printTo3(int n){
	int arr[10];
	int len=0;
	
	while(n>0){
		if(n%3==2){
			arr[len++]=-1;
			n=(n+1)/3;
		}else{
			arr[len++]=n%3;
			n=n/3;
		}
	}
	for(int i=len-1;i>=0;i--){
		cout<<arr[i]*a[i]<<' ';
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printTo3(n); 
	return 0;
} 
