#include <iostream>
using namespace std;
int main()
{
	for(int i=1800;i<1900;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(j*j==j+i)
			{
				cout<<i<<endl;
				return 0; 
			} 
		}
	}
	return 0;
}
