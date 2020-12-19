#include <iostream>
#include <cmath>
using namespace std;
int fun(int num){
	
}
int main(){
	int n;
	cin>>n;
	int num=pow(n,3);
	//cout<<num<<endl;
	int t=0;
	for(int i=1;i<num;i+=2){
		t=0;
		for(int j=i;j<num;j+=2){
			if(t+j==num){
				cout<<i;
				return 0;
			}else if(t+j>num)
				break;
			else
				t+=j;
		}
	}
	return 0;
}
