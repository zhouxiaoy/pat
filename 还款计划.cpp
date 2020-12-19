#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int bj,hk;
	double r;
	int n,min=bj,index=-1;
	cin>>r>>n;
	for(int i=1;i<1000000;i++){
	hk=i;
	double bj=1000000;
	for(int j=0;j<n;j++){
		
		bj=bj+bj*(r/1200)-hk;
		bj=(double)(int)(bj+0.5);
	}
	if(abs(bj)<min){
	index=i;
	min=abs(bj);	
	}
	else if(abs(bj)==min)
	if(i<index)
	index=i;
	}
	cout<<index<<endl;
	cout<<min<<endl;
	return 0;
}


