#include<cstdio>
#include<cstring>

int n;
int a[110][110];
int b[110];

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);

        int Max = -32767;
        for(int i=0; i<n; i++)
        {
            //����b��ʾi~j�У���Ӧ��Ԫ�صĺ�
            //����ά��̬�滮����ת��Ϊһά��̬�滮����
            memset(b, 0, sizeof(b));
            for(int j=i; j<n; j++)
            {
                //�������������b������Ӷκ͵Ķ�̬�滮�㷨
                int sum=0;
                for(int k=0; k<n; k++)
                {
                    b[k] += a[j][k];
                    sum += b[k];
                    if(sum<0) sum = b[k];
                    if(sum>Max) Max = sum;
                }
            }
        }
        printf("%d\n",Max);
    }

    return 0;
}

