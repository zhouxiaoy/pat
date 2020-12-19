#include <iostream>
using namespace std;
//判断是否是闰年
int judge(int n){
	if(n % 400 ==0||(n%4==0&&n%100!=0))
		return 366;
	else
		return 365;
} 
int main(){
	int sum=0;
	int xq =6;//一开始是星期六 
	for(int i=1950;i<2013;i++){
		if((judge(i)+xq)%7==0){
			sum++;
			cout<<i<<endl;
		}
		xq = (judge(i)+xq)%7; 
	}
	cout<<sum;
	return 0;
} 
