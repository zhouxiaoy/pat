#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5+5;
int n;
int st[N];
bool vis[N];
int maxlength = 0;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&st[i]);
    
    int i=0,j=0;
    while(j<n){
        if(vis[st[j]]==false){//�ڵ�ǰ�����и�����û���ֹ�
            vis[st[j]] = true;
            j++;
        }else{//����������ظ�����
            maxlength  = max(maxlength,j-i);
            while(st[i]!=st[j]){
                vis[st[i]] = false;//��֮ǰ������
                i++;
            }
            //cout<<maxlength<<"֮ǰ��λ�ã�"<<i<<' '<<j;
            i++;//�ҵ�֮������ǰ��һλ
            j++;
            //cout<<"���ڵ�λ��"<<i<<' '<<j<<endl;
        }
    }
    maxlength = max(maxlength,j-i);
    printf("%d\n",maxlength);
    return 0;
}
