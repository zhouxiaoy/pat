#include <iostream>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	for(int i=1;i<1000;i++){
		for(int j=i+1;j<1000;j++){
			if(97*j-127*i==1){
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	} 
	return 0; 
}
