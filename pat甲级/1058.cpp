#include <iostream>
#include <cstdio> 
using namespace std;

int main(){
	int a,b,c;
	int a1,a2,b1,b2,c1,c2;
	scanf("%d.%d.%d",&a1,&b1,&c1);
	scanf("%d.%d.%d",&a2,&b2,&c2);
	
	c = c1+c2;  
	b = b1+b2;
	a = a1+a2;
	b+= c/29;c = c%29;
	a += b/17; b= b%17;
	printf("%d.%d.%d",a,b,c);
	return 0;
} 
