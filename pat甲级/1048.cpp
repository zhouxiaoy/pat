#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005]; 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	
	int begin = 0,end = n-1;
	while(begin<end){
		if(a[begin]+a[end]<m)
			begin++;
		else if(a[begin]+a[end]>m)
			end--;
		else{
			printf("%d %d\n",a[begin],m-a[begin]);
			return 0;
		}
	}
	puts("No Solution");
	return 0;
} 
