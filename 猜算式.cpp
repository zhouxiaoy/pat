#include <iostream>

using namespace std;
int main()
{
	for(int i=100;i<=999;i++)
	{
		
		for(int j=100;j<=999;j++)
		{
			int sum[10]={0};
			int a=i%10,b=(i/10)%10,c=i/100,d=j%10,e=(j/10)%10,f=j/100;
			sum[a]++;
			sum[b]++;
			sum[c]++;
			sum[d]++;
			sum[e]++;
			sum[f]++;
			if(sum[a]>2||sum[b]>2||sum[c]>2||sum[d]>2||sum[e]>2||sum[f]>2)
			continue;
			
			if(i*d<100||i*d>=1000||i*f<100||i*f>=1000||e*i<100||e*i>=1000)
			continue;
			
			a=(i*d)%10;
			b=(i*d/10)%10;
			c=(i*d)/100;
			sum[a]++;
			sum[b]++;
			sum[c]++;
			if(sum[a]>2||sum[b]>2||sum[c]>2)
			continue;
			
			a=(i*e)%10;
			b=(i*e/10)%10;
			c=(i*e)/100;
			sum[a]++;
			sum[b]++;
			sum[c]++;
			if(sum[a]>2||sum[b]>2||sum[c]>2)
			continue;
			
			a=(i*f)%10;
			b=(i*f/10)%10;
			c=(i*f)/100;
			sum[a]++;
			sum[b]++;
			sum[c]++;
			if(sum[a]>2||sum[b]>2||sum[c]>2)
			continue;
			
			a=(i*j)%10;
			b=(i*j/10)%10;
			c=(i*j/100)%10;
			d=(i*j/1000)%10;
			e=(i*j)/10000;
			sum[a]++;
			sum[b]++;
			sum[c]++;
			sum[d]++;
			sum[e]++;
			if(sum[a]>2||sum[b]>2||sum[c]>2||sum[d]>2||sum[e]>2)
			continue;
			
			cout<<i*j<<endl; 
		}	
	}
	return 0;
}

