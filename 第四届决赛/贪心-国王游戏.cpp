#include <iostream>
#include <algorithm>
using namespace std;
typedef struct peo {
	int a;
	int b;
}peo;
bool cmp(const peo &a, const peo &b) {
	return a.a*a.b < b.a*b.b;
}
int lens = 1;
int sum[10010] = { 0,1 }, num[10010];
void muti(long long x) {
	int tmp = 0;
	for (int i = 1; i <= lens; i++) {
		sum[i] *= x;
	}
	for (int i = 1; i <= lens; i++) {
		tmp += sum[i];
		sum[i] = tmp % 10;
		tmp /= 10;
	}
	while (tmp != 0) {
		lens++;
		sum[lens] = tmp % 10;
		tmp /= 10;
	}
}
int main() {
	int n;
	cin >> n;
	peo king, dac[10005];
	cin >> king.a >> king.b;
	for (int i = 0; i < n; i++) {
		cin >> dac[i].a >> dac[i].b;
	}
	sort(dac, dac + n, cmp);
	//计算前面所有的 人的a的乘积 （大精度乘法） 
	muti(king.a);
	for (int i = 0; i < n - 1; i++) {
		muti(dac[i].a);
	}
	long long tmp = 0;
	//大精度除法 

	for (int i = lens; i >= 1; i--) {
		tmp *= 10;
		tmp += sum[i];
		if (tmp >= dac[n - 1].b) {
			num[i] = tmp / dac[n - 1].b;
			tmp = tmp % dac[n - 1].b;
		}
	}
	int i = lens;
	while (num[i] == 0)i--;
	while (i >= 1) {
		cout << num[i];
		i--;
	}
	return 0;
}
