#include <iostream>
#include <memory.h>
#include <list>
using namespace std;

int n, m;

int CalcCount(int num, list<int>& path) {
	if (num == n) {
		return 0;
	}
	while (num > n) {
		if (num % 2 == 0 && (num / 2) > n)
			n /= 2;
		else
			n--;
		path.push_back(n);
	}
	path.reverse();
	return (int)path.size();
}

int CalcCount1(int num, int* pCount, int *pPre) {
	if (num == n) {
		pCount[num] = 0;
		return 0;
	}
	if (num % 2 == 1) {
		if (pCount[num - 1] == 0)
			pCount[num - 1] = CalcCount1(num - 1, pCount, pPre);
		pPre[num] = num - 1;
		pCount[num] = pCount[num - 1] + 1;
	}
	else {
		int n2 = num / 2;
		if (n2 >= n && pCount[n2] == 0) {
			pCount[n2] = CalcCount1(n2,pCount,pPre);
		}
		if (pCount[num - 1] == 0)
			pCount[num - 1] = CalcCount1(num - 1, pCount, pPre);
		if (n2 >= n && pCount[n2] < pCount[num - 1]) {
			pPre[num] = n2;
			pCount[num] = pCount[n2] + 1;
		}
		else {
			pPre[num] = num - 1;
			pCount[num] = pCount[num - 1] + 1;
		}
	}
	return pCount[num];
}

int main() {
	cin >> n >> m;
	int *pCount = new int[m + 1];
	int *pPre = new int[m + 1];
	memset(pCount + n, 0, sizeof(int)*(m - n));
	memset(pPre + n, 0, sizeof(int)*(m - n));
	cout << CalcCount1(m, pCount, pPre) << endl << m << "\t";

	//求2015的变化过程
	while (m >n) {
		cout << pPre[m] << '\t';
		m = pPre[m];
	}
	delete[] pCount;
	delete[] pPre;
	return 0;
}
