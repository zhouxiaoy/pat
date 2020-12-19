#include <iostream>
using namespace std;
int main()
{
	int n=0;
	int temp=6;
	for(int i=1949;i<=2012;i++)
		{
			if(temp==7)n++;
			if(temp<7)
			temp++;
			else
			temp=1;
		}
		cout<<n;
	return 0;
} 
