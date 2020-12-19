#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct station{
	double price;
	int distance;	
};

bool cmp(station a,station b){
		return a.distance<b.distance;
}

station e[505];
int main(){
	int cmax,dis,d_avg,n;
	cin>>cmax>>dis>>d_avg>>n;
	for(int i=0;i<n;i++){
		cin>>e[i].price>>e[i].distance;
	}
	sort(e,e+n,cmp);
	
	for(int i=0;i<n;i++)
		printf("%.02f %d\n",e[i].price,e[i].distance);

	return 0;
}
