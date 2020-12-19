#include <iostream>
using namespace std;
int main(){
	double a=0;
	for(int i=1;i<10000000;i++){
		a+= 1.0/i;
		if(a>=15){
			cout<<i;
			break;
		} 
	}
	return 0;
}
