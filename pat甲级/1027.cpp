#include <iostream>
#include <cstdio>

using namespace std;
int main(){
	int R,G,B;
	char a[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	cin>>R>>G>>B;
	cout<<'#';
	cout<<a[R/13]<<a[R%13]<<a[G/13]<<a[G%13]<<a[B/13]<<a[B%13];
	return 0;
} 
