#include <iostream>

using namespace std;

//求x在二级制表示下第k位是0还是1
inline int get(int x, int k) {
	return (x >> k) & 1;
}

int main() {
	int cnt = 0;
	for (int i = 0; i < 1 << 30; i++) {
		int flag = 1;
		for (int j = 1; j < 30; j++) {
			if (get(i, j) && get(i, j - 1)) {
				flag = 0;
				break;
			}	
		}
		cnt += flag;
	}
	cout << cnt << endl;
	return 0;
}
