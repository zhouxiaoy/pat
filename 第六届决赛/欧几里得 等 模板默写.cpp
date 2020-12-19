#include <iostream>
#include <cstdio>
using namespace std;
//辗转相除求最大公倍数 
int gcd(int n,int m){
	return n==0?m:gcd(n,m%n);
}
//判断是否是闰年 
bool isPrime(int n){
	if((n%4==0&&n%100!=0)||n%400==0){
		return true;
	}
	return false;
}
// 扩展欧几里得
//调用后完成xy是ax+by==gcd（a，b）的解
long ext_gcd(long a,long b){
	int x,y;
	if(b==0){
		x=1;
		y=0;
		return 0;
	}
	long res = ext_gcd(b,a%b);
	long x1 = x;//备份x 
	x=y;//更新x 
	int y1=x1-a/b*y;//更新y
	return res; 
}
//快速幂
long long power(long long a,long long b){
	long long c = 1;
	while(b){
		if(b&1)c=(c*a);
		b>>=1;
		a=a*a;
	}
	return c;
} 
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	//cout<<gcd(m,n);
	cout<<power(m,n);
	return 0;
} 

long long ext_gcd(long a,long b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	else{
		long r = ext_gcd(b,a%b,x,y);
		long t = x;
		x = y;
		y = t-a/b*y;
		return r; 
	}
}
