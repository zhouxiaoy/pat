#include<iostream>
using namespace std;
#define maxn 10000
int w[maxn][maxn];//前一个参数表示当前起点的距离  后一个参数表示之后的终点的距离
int n, L;//n表示人数，L表示路程长度
struct
{
    int dis, pop;//dis表示距离起点的距离,pop表示当前的人数
}p[maxn];

int min(int x, int y)//取最小的函数
{
    return x < y ? x : y;
}
//分治法
int solve(int start, int end, int cur)//起点  终点  带划分区域
{
    if (cur == 0)return w[start][end];
	
    int ML, MR, M;
    M = 2*L;//初始化  M的距离
    //M = 2 * w[0][L];
    int m;
    for ( m = start + 1; m < end; m++)//由于
    {
        ML = solve(start, m, cur - 1);
        MR = solve(m, end, cur - 1);
        M = min(M, MR + ML);
    }
    
    if(cur==1){
    	cout<<"第三个"<<m<<endl;
    }
    
    return M;
}

int main()
{
    cin >> n >> L;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].dis >> p[i].pop;
    }
    for (int i = 0; i <= L; i++)//起点
    {
        for (int j = i; j <= L; j++)//终点
        {
            for (int k = 0; k < n; k++)//对所有家庭遍历
            {
                if (p[k].dis > i&&p[k].dis<j)//人家的距离必须位于起点与终点之间
                {
                    w[i][j] += (j - p[k].dis)*p[k].pop;//每个对应的距离的开销和
                }
            }
        }
    }
     for (int i = 0; i <= L; i++)//起点
    {
        for (int j = 0; j <= L; j++)//终点
        {
        	cout<<w[i][j]<<' '; 
        }
        cout<<endl;
	} 
    cout << solve(0, L, 2);
    return 0;
}
//1 2 3 4 5  6 7 8 9 10
//3 2 0 5 20 5 0 7 0 0
