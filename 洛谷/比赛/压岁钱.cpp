#include <iostream>

using namespace std;
long long data[1000005];
int main(){
	int m,sum=0;
	long long money=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		money += data[i];
		
		int type,a,b;
		cin>>type>>a;
		if(type == 1){
			money += a;
		}
		else if(type == 2){
			if(money - a<0)
				sum++;
			else
				money -= a;
		}
		else{
			cin>> b;
			data[b] += a;
			money -= a;
		}
		//cout<<money<<","<<endl;
	}

	cout<<sum;
	return 0;
} 
