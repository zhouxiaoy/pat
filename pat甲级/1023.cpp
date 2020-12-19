#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, str1;
	cin >> str;
	str1 = str;
	int a[10] = { 0 }, b[10] = { 0 };
	int c = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		int d = str[i] - '0';
		a[d]++;
		b[(2 * d + c) % 10]++;
		str1[i] = ((2 * d + c) % 10) + '0';
		c = (2 * d + c) / 10;
	}
	int i = 0;
	while (i < 10) {
		if (a[i] != b[i])
			break;
		i++;
	}

	if (c != 0 || i != 10)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	if (c != 0)cout << c;
	for (int i = 0; i < str1.size(); i++)
		cout << str1[i];
	return 0;
}
