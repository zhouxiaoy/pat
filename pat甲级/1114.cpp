#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int p[10000],cnt[10000],area[10000],ans[10000];//����㣬�����������������,�ڵ�����

bool cmp(int a,int b){
    if(area[a]*ans[b] != area[b]*ans[a])//ƽ�������ͬ�����������
        return area[a]*ans[b] > area[b]*ans[a];
    return a<b;//�����ͬ����id����
}

int find(int x){//�ҵ����ڵ�
    if(x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void add(int a,int b){
    a = find(a);
    b = find(b);
    //cout<<a<<" "<<area[a]<<' '<<b<<' '<<area[b]<<endl;
    if(a<b) {//���a�ĸ��ڵ�<b�ĸ��ڵ㣬��b������a��
        p[b] = a;
        cnt[a] += cnt[b];//����a���ķ�����
        area[a] += area[b];//����a���ķ��������
        ans[a] += ans[b];//����a���Ľ�����
    }else if(a>b){//a>b���෴
        p[a] = b;
        cnt[b] += cnt[a];
        area[b] += area[a];
        ans[b] += ans[a];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    set<int> nodes;//�ݴ���ֵĽڵ�
    vector<int> isRoot;//���Ҫ����ĵĸ��ڵ�
    //��ʼ��
    for(int i=0;i<10000;i++) {
        p[i] = i;ans[i] = 1;
    }
    int id,f,m,s,s_cnt,x,y;
    for(int i=0;i<n;i++){
        //����ڵ�id�����׽ڵ㣬ĸ�׽ڵ㣬���ӽڵ�����
        scanf("%d%d%d%d",&id,&f,&m,&s_cnt);
        nodes.insert(id);
        if(f != -1)  nodes.insert(f),add(f,id);//�ϲ�����;
        if(m != -1) nodes.insert(m),add(m,id);//�ϲ�ĸ��
        for(int j=0;j<s_cnt;j++){
            scanf("%d",&s);
            nodes.insert(s);
            add(s,id);//�ϲ�����
        }
        scanf("%d%d",&x,&y);//����Ҫ��x��y�Ƚ��ܣ������ܵĻ���ֱ�Ӹ�ֵ�������ǰ�ڵ�պ���֮ǰ���ĸ���㣬�Ḳ��֮ǰ����Ϣ
        area[id] += y;cnt[id] += x;
        if(find(id) != id){//˵��֮ǰ�Ѿ���Ϊ�ӽڵ���߸��ڵ�������У�Ҫ�����ݼ��뵽����
            cnt[p[id]] += x;//��������x��y����Ϊ��֮ǰ��ĳ�������ڵ㣬���ڼ���id����ؽڵ������һ�����ϲ��ˣ��ͻ�����֮ǰһ�����Ľڵ�����
            area[p[id]] += y;
        }
        //cout<<id<<"��root�ǣ�"<<p[id]<<" "<<cnt[p[id]]<<" "<<area[p[id]]<<" "<<ans[p[id]]<<endl;
    }
    
    //���������ȥ�������ڵ㣨ѡ��set���Ա������ظ��Ľڵ㣩
    for(auto it = nodes.begin();it != nodes.end();it++)
        //cout<<*it<<' '<<ans[p[*it]]<<' '<<area[p[*it]]<<endl;
        if(p[*it] == *it)//�Ǹ���㣬����
            isRoot.push_back(*it);

    sort(isRoot.begin(),isRoot.end(),cmp);
    cout<<isRoot.size()<<endl;
    for(int i=0;i<isRoot.size();i++)
        printf("%04d %d %.3lf %.3lf\n",isRoot[i],ans[isRoot[i]],cnt[isRoot[i]]*1.0/ans[isRoot[i]],area[isRoot[i]]*1.0/ans[isRoot[i]]);
}
