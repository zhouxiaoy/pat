#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a[103][103];
int b[103][103]={0};  // ǰ׺�����飬�൱�����ĵ� sum[]
int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      b[i][j] =b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j];  // ��ǰ׺��
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ",b[i][j]);
	cout<<endl;
 }
  int ans = 1;

  int l = 2;
  while (l <= min(n, m)) {
    for (int i = l; i <= n; i++) {
      for (int j = l; j <= m; j++) {
        if (b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l] == l * l) {
          ans = max(ans, l);
        }
      }
    }
    l++;
  }

  cout << ans << endl;
  return 0;
}
