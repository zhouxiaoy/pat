#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[25];
	for(int i=1;i<=n;i++){
		 scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(i%2==0){
				printf("YES");
				return 0;
			}
			break;
		}	
	} 
	for(int i=n;i>=1;i--){
		if(a[i]==0){
			if((n-i+1)%2==0){
				printf("YES");
				return 0;
			}
			break;
		}
	}
	printf("NO");
	return 0;
} 
