#include<iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;
const int inf = 0x3f3f3f3f;
int d[N][N];//d[i][j]���i��j����Ҫ�Ŀ���
int n, m;
int  cost[N], dis[N];//cost��Ź�·�� ��dis[i]��ʾ����i��С�Ŀ���
bool vis[N];//�жϸýڵ��Ƿ�ѡ

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
		dis[begin] = 0;//�����ʼ��
		
		for (int i = 1; i <= n; i++)
		{
			int minn = inf, v = -1;
			//ѡ���ڵ�ǰ���ܵ������С�Ľ��
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
				//���δ��ѡ����v��k�ɵ���
				if (vis[k] == false && d[v][k] != -1)
				{//���½ڵ���Ϣ
					if (dis[v] + cost[k] + d[v][k] < dis[k])
					{
						dis[k] = dis[v] + cost[k] + d[v][k];
					}
				}
			}
		}

		//����end�Ĺ�·��
		if (dis[end] != inf)
			printf("%d\n", dis[end]-cost[end]);
		else
			printf("-1\n");
	}
	return 0;
}
