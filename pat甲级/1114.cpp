#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int p[10000],cnt[10000],area[10000],ans[10000];//根结点，房子数量，房子面积,节点数量

bool cmp(int a,int b){
    if(area[a]*ans[b] != area[b]*ans[a])//平均面积不同，按面积排序
        return area[a]*ans[b] > area[b]*ans[a];
    return a<b;//面积相同，按id排序
}

int find(int x){//找到根节点
    if(x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void add(int a,int b){
    a = find(a);
    b = find(b);
    //cout<<a<<" "<<area[a]<<' '<<b<<' '<<area[b]<<endl;
    if(a<b) {//如果a的根节点<b的根节点，将b树插入a树
        p[b] = a;
        cnt[a] += cnt[b];//更新a树的房子数
        area[a] += area[b];//更新a树的房子总面积
        ans[a] += ans[b];//更新a树的结点个树
    }else if(a>b){//a>b，相反
        p[a] = b;
        cnt[b] += cnt[a];
        area[b] += area[a];
        ans[b] += ans[a];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    set<int> nodes;//暂存出现的节点
    vector<int> isRoot;//最后要输出的的根节点
    //初始化
    for(int i=0;i<10000;i++) {
        p[i] = i;ans[i] = 1;
    }
    int id,f,m,s,s_cnt,x,y;
    for(int i=0;i<n;i++){
        //输入节点id，父亲节点，母亲节点，孩子节点数量
        scanf("%d%d%d%d",&id,&f,&m,&s_cnt);
        nodes.insert(id);
        if(f != -1)  nodes.insert(f),add(f,id);//合并父亲;
        if(m != -1) nodes.insert(m),add(m,id);//合并母亲
        for(int j=0;j<s_cnt;j++){
            scanf("%d",&s);
            nodes.insert(s);
            add(s,id);//合并孩子
        }
        scanf("%d%d",&x,&y);//必须要用x，y先接受，不接受的话，直接赋值，如果当前节点刚好是之前树的根结点，会覆盖之前的信息
        area[id] += y;cnt[id] += x;
        if(find(id) != id){//说明之前已经作为子节点或者父节点加入树中，要把数据加入到树中
            cnt[p[id]] += x;//这里必须加x和y，因为它之前是某颗树根节点，现在加上id的相关节点后，与另一颗树合并了，就会多加了之前一颗树的节点数据
            area[p[id]] += y;
        }
        //cout<<id<<"的root是："<<p[id]<<" "<<cnt[p[id]]<<" "<<area[p[id]]<<" "<<ans[p[id]]<<endl;
    }
    
    //保留根结点去掉其他节点（选用set可以避免有重复的节点）
    for(auto it = nodes.begin();it != nodes.end();it++)
        //cout<<*it<<' '<<ans[p[*it]]<<' '<<area[p[*it]]<<endl;
        if(p[*it] == *it)//是根结点，保存
            isRoot.push_back(*it);

    sort(isRoot.begin(),isRoot.end(),cmp);
    cout<<isRoot.size()<<endl;
    for(int i=0;i<isRoot.size();i++)
        printf("%04d %d %.3lf %.3lf\n",isRoot[i],ans[isRoot[i]],cnt[isRoot[i]]*1.0/ans[isRoot[i]],area[isRoot[i]]*1.0/ans[isRoot[i]]);
}
