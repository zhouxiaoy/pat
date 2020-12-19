#include <iostream>
#include <cstdio> 
using namespace std;
int main(){
	int ans=0,n;
	int num[500005];
	scanf("%d",&n);
	// 1 = 2^0
	// 3 = 2^1 + 2^0
	// 6 = 2^2 + 2^1
	// 9 = 2^3 + 2^0
	// 12= 2^3 + 2^2 + 2^0
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		ans=ans^num[i];
	}
	if(ans==0)printf("lose");
	else 
	{
		for(int i=1;i<=n;i++){
			if((num[i]^ans)<num[i]){
				printf("%d %d\n",num[i]-(num[i]^ans),i);
				num[i]=num[i]^ans;
				break;
			} 
		}
		for(int i=1;i<=n;i++){ 
			if(i!=1)
				printf(" ");
			printf("%d",num[i]); 
		} 
	}
	return 0;
} 
