#include <iostream>
using namespace std;
//�ж��Ƿ�������
int judge(int n){
	if(n % 400 ==0||(n%4==0&&n%100!=0))
		return 366;
	else
		return 365;
} 
int main(){
	int sum=0;
	int xq =6;//һ��ʼ�������� 
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
