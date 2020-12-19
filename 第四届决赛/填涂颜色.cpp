#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[35][35] = { 0 }, b;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
bool vis[35][35];
void dfs(int x, int y) {
	if (x<0 || x>n + 1 || y<0 || y>n + 1 || a[x][y] == 1)
		return;
	a[x][y] = 0;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(!vis[xx][yy])
			dfs(xx, yy);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &b);
			if (b == 0)a[i][j] = 2;
			else a[i][j] = b;
		}
	}

	dfs(0, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
