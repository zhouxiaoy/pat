#include <iostream>
using namespace std;
int getSum(int x){
	int sum=0;
	while(x>0){
		sum+=x%10;
		x=x/10;
	}
	return sum;
} 
int main(){
	for(int i=1988;i>=0;i--){
		if(2014-i==getSum(i)){
			cout<<i<<endl;
		}
	}
	return 0;
} 
