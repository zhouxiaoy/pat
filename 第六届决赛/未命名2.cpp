#include <iostream>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a,ll b,ll &x,ll& y){
	ll r,t;
	if(b==0){
		x=1;
		y=0;
		return a;
	}else{
		r=exgcd(b,a%b,x,y);
		t=x;
		x=y;
		y=t-a/b*y;
	}
}
int main(){
	itn m;
	return 0;
}
