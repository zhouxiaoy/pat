#include <iostream>
using namespace std;
int main(){
	for(int i=1;i<200;i++){
		int temp=200-i-20*i;
		if(temp%5==0&&temp/5!=0){
			cout<<i*11+temp/5;
			break;
		} 
	}
	return 0;
} 
