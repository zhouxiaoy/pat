#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define x first
#define y second
typedef pair<int,int>PII;
const int N = 5;
char st[N][N],backup[N][N]; 

int get(int x,int y){
	return x*4+y;
}

void turn(int x,int y){
	if(st[x][y]=='+')st[x][y] = '-';
	else st[x][y] = '+';
}

void turn_all(int x,int y){
	for(int i=0;i<4;i++){
		turn(x,i);
		turn(i,y);
	}
	turn(x,y);
}

int main(){
	for(int i=0;i<4;i++)cin>>st[i];
	
	vector<PII> res;
	for(int k = 0;k< 1<<16;k++){
		vector<PII> temp;
		memcpy(backup,st,sizeof st);
		
		//进行操作
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(k >> get(i,j) & 1){
					temp.push_back({i,j});
					turn_all(i,j);
				} 
		
		bool has_closed = false;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(st[i][j] == '+')
					has_closed = true;
		
		if(!has_closed)
			if(res.empty()||temp.size()<res.size())
				res = temp; 
		
		memcpy(st,backup,sizeof st);
	}
	cout<<res.size()<<endl;
	for(auto it:res)cout<<it.x+1<<' '<<it.y+1<<endl;
	return 0;
} 

/* 
//会超时  需要使用二进制优化 

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5;
char st[N][N];
int vis[N][N],backup[N][N];
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
int minn = 0x3f3f3f3f;

void turn(int x, int y) {
	if (st[x][y] == '-')st[x][y] = '+';
	else st[x][y] = '-';
	return;
}

void turn_all(int x, int y) {
	for(int i=-3;i<4;i++){
			int a = i + x, b = i + y;
			if (a>=0&&a<=3)
				turn(a, y);
			if (a == x && b == y)continue;
			if (b >= 0 && b <= 3)
				turn(x, b);
		}
}

void dfs(int x, int y, int step) {
	if (x == 3 && y == 3) {
		int flag = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (st[i][j] == '+')flag = true;
		if (!flag){
			if(step<minn){
				minn = step;
				memcpy(backup,vis,sizeof vis);
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= 4 || b < 0 || b >= 4)continue;
		if (vis[a][b]==0) {
			vis[a][b] = 1;
			//按 
			turn_all(a, b);
			dfs(a, b, step + 1);
			turn_all(a, b);
			//不按
			vis[a][b]=2;
			dfs(a, b, step);
			vis[a][b] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++)cin >> st[i];
	dfs(-1, 0, 0);
	cout << minn << endl;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(backup[i][j]==1)
				cout<<i+1<<' '<<j+1<<endl;
			
	return 0;
}
*/ 
