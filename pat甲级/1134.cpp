//��ȷ �汾 ����temp��pa������ǵڼ�����
//ֻҪ ÿ���߶������ˣ�Yes 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    vector<int> pa[n];
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        pa[a].push_back(i);
        pa[b].push_back(i);
    }
    
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int t;
        scanf("%d",&t);
        vector<bool> temp(m,false);
        while(t--){
            scanf("%d",&a);
            for(auto v1:pa[a])
                temp[v1] = true;
        }
        bool flag = true;
        for(int t =0;t<m;t++){
            if(!temp[t])
                flag = false;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}

//����汾
//�� vis��temp�����Щ�㱻���ù�
//���vis����temp����һ������ÿ���㶼������
//���������һ����û���ù�����ÿ����㶼���ܱ��ù� 
/* 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool vis[1005];
vector<int> pa[1005];

int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        vis[a] = vis[b] = true;
        pa[a].push_back(b);
        pa[b].push_back(a);
    }
    
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int t;
        scanf("%d",&t);
        bool temp[1005]={0};
        while(t--){
            scanf("%d",&a);
            //cout<<"a.size() = "<<pa[a].size()<<endl;
            for(auto v1:pa[a]){
                temp[a] = true;
                temp[v1] = true;
            }
        }
        bool flag = true;
        for(int t =0;t<n;t++){
            printf("%d %d %d\n",t,temp[t],vis[t]);
            if(vis[t] != temp[t]){
                flag = false;
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
*/ 
