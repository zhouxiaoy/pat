#include <iostream>
using namespace std;
char s[17];
long long fac(int x){
	long long  ans = 1;
	for(int i = 2; i <= x; i++) ans *= i;
	return ans; 
}
void arrayToInt(){
	long long ans = 0;
	for(int i = 0; i < 17; i++){
		int temp = 0;
		for(int j = i+1; j <17; j++){
			if(s[j] < s[i]) temp++;
		ans += temp * fac(17 - i -1);
		}
	}
	cout<<ans;
}
 
int main(){
	cin>>s;
	arrayToInt();
	return 0;
} 
