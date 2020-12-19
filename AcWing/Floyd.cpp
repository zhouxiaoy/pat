#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;
const int inf = 0x3f3f3f3f;
int d[N][N];//d[i][j]存放i从j所需要的开销
int n, m;
int  cost[N], dis[N];//cost存放过路费 ，dis[i]表示到达i最小的开销
bool vis[N];//判断该节点是否被选

int main() {
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> d[i][j];
	for (i = 1; i <= n; i++) cin >> cost[i];
	cin >> m;


	for (int u = 1; u <= m; u++)
	{
		memset(vis, false, sizeof vis);
		memset(dis, inf, sizeof dis);

		int begin, end;
		cin >> begin >> end;
		dis[begin] = 0;//标记起始点
		
		for (int i = 1; i <= n; i++)
		{
			int minn = inf, v = -1;
			//选出在当前所能到达的最小的结点
			for (int j = 1; j <= n; j++)
			{
				if (vis[j] == false && dis[j] < minn)
				{
					minn = dis[j];
					v = j;
				}
			}

			if (v == -1)
				break;

			vis[v] = true;
			for (int k = 1; k <= n; k++)
			{
				//结点未被选择并且v到k可到达
				if (vis[k] == false && d[v][k] != -1)
				{//更新节点信息
					if (dis[v] + cost[k] + d[v][k] < dis[k])
					{
						dis[k] = dis[v] + cost[k] + d[v][k];
					}
				}
			}
		}

		//减掉end的过路费
		if (dis[end] != inf)
			printf("%d\n", dis[end]-cost[end]);
		else
			printf("-1\n");
	}
	return 0;
}
