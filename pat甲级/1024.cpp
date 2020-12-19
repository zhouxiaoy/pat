#include <iostream>
#include <string>
using namespace std;

char a[200] = { 0 }, b[200] = { 0 };

bool isHuiWen(int l) {
	int i = 0;
	while (i < l) {
		if (a[i] != a[l-1])
			return false;
		i++, l--;
	}
	return true;
}

int main() {
	long long n;
	int k,length,k1;
	cin >> n >> k;
	k1 = 0;
	string str = to_string(n);
	length = str.size();
	for (int i = 0; i < str.size(); i++)
		a[i] = str[i];
	//一开始就是回文，直接输出
	if (isHuiWen(str.size())) {
		cout << n << endl<<0<<endl;
		return 0;
	}
	while (k1 < k) {
		int c = 0;
		for (int i = 0; i <length; i++)
			b[i] = a[length-i-1];
		for (int i = 0; i < length; i++) {
			int d = (b[i] - '0' + a[i] - '0' + c) / 10;
			a[i] = (a[i]-'0'+b[i] - '0' + c)%10 + '0';
			c = d;
		}
		if (c != 0) {
			a[length] = c + '0';
			length++;
		}
		k1++;
		if (isHuiWen(length))
			break;
	}

	for (int i = length-1; i >= 0; i--)
		cout << a[i];
	cout <<endl<< k1<<endl;
	return 0;
}
