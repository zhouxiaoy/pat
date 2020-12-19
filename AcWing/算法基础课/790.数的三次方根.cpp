#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	double db;
	cin>>db;
	
	double l = -10000.0,r = 10000;//其中r必须为10000.0 否者（数据-43.42）会出错 
	while(r - l > 1e-8){
		double mid = (l + r) / 2;
		if(mid * mid * mid >= db) r = mid;
		else l = mid;
	}
	printf("%lf",l);
	return 0;
}
