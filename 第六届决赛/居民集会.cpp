#include<iostream>
using namespace std;
#define maxn 10000
int w[maxn][maxn];//ǰһ��������ʾ��ǰ���ľ���  ��һ��������ʾ֮����յ�ľ���
int n, L;//n��ʾ������L��ʾ·�̳���
struct
{
    int dis, pop;//dis��ʾ�������ľ���,pop��ʾ��ǰ������
}p[maxn];

int min(int x, int y)//ȡ��С�ĺ���
{
    return x < y ? x : y;
}
//���η�
int solve(int start, int end, int cur)//���  �յ�  ����������
{
    if (cur == 0)return w[start][end];
	
    int ML, MR, M;
    M = 2*L;//��ʼ��  M�ľ���
    //M = 2 * w[0][L];
    int m;
    for ( m = start + 1; m < end; m++)//����
    {
        ML = solve(start, m, cur - 1);
        MR = solve(m, end, cur - 1);
        M = min(M, MR + ML);
    }
    
    if(cur==1){
    	cout<<"������"<<m<<endl;
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
    for (int i = 0; i <= L; i++)//���
    {
        for (int j = i; j <= L; j++)//�յ�
        {
            for (int k = 0; k < n; k++)//�����м�ͥ����
            {
                if (p[k].dis > i&&p[k].dis<j)//�˼ҵľ������λ��������յ�֮��
                {
                    w[i][j] += (j - p[k].dis)*p[k].pop;//ÿ����Ӧ�ľ���Ŀ�����
                }
            }
        }
    }
     for (int i = 0; i <= L; i++)//���
    {
        for (int j = 0; j <= L; j++)//�յ�
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
