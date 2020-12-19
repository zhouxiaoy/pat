#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
// �Ƿ������� 
bool isLun(int year){
	if(year%400==0||(year%4==0&&year%100!=0))
		return true;
	else
		return false;
}
//�ж��Ƿ�Ϊ���� 
bool isPrime(int n){
	if(n<=1)
		return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return false;
	}
	return true;
}
//������(������ʱʹ��int����Ҫʱʹ��long)
int K_M(int a,int n){
	int c=1;
	while(n){
		if(n&1)
			c=c*a;
		a=a*a;
		n>>=1;
	}
	return c;
}
//��չŷ�����
ll ex_gcd(ll a,ll b,ll &x,ll&y){
	ll r,t;
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		r=ex_gcd(b,a%b,x,y);
		t=x;
		x=y;
		y=t-a/b*y;
		return r;
	}
}
//ŷ�����
int gcd(int b,int a){
	return b==0?a:gcd(b,a%b);	
} 
int main(){
	int m,n;
	while(cin>>m>>n)
		cout<<K_M(m,n)<<endl; 
	return 0;
} 
