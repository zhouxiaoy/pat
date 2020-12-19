#include <iostream>
using namespace std;
int check(int a[],int n){
	int i=5;
	int b[10]={0};
	while(n>0){
		if(i==1){
			if(b[n%10]==1)
				b[n%10]++;
			else
				return 0;
		}
		else{
			if(b[n%10]!=0)
				return 0;
			else
				b[n%10]++;
		}
		a[i--]=n%10;
		n/=10;
	}
	return 1;
}
int main(){
	for(int i=100;i<=999;i++){
		int a,b,c;
		a=i/100,b=(i/10)%10,c=i%10;
		if(a!=b&&b!=c&&a!=c){
			if(i*i>=100000&&i*i<=999999){
				//cout<<i<<endl;
				int num[6]={0};
				if(check(num,i*i)){
					if(a==num[0]&&b==num[5]){
						cout<<i;
					}
				}
			}
			
		}
	}
	return 0;
} 
