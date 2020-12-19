#include <iostream>
using namespace std;
int main(){
	int a='M'-'A'+10;
	int b=10;
	int c='N'-'A'+10;
	int d='Y'-'A'+10;
	int sum=a*36*36*36;
	sum+=b*36*36;
	sum+=c*36;
	sum+=d;
	cout<<sum;
	return 0;
}
