/*
//����ᳬʱ
#include <iostream>
#include <cstdio>
using namespace std;

int n;
int v[100005];
void sort(int begin,int end){
    if(begin>=end)return;
    int t = v[end],l = begin, r = end;
    while(l<r){
        //���ұ��ҳ�С�ڱ�׼�ĵ�һ����
        while(l<r&&v[l]<=t)l++;
        if(l<r)
            v[r--] = v[l];
        //���ұ��ҵ�С�ڱ�׼�ĵ�һ����
        while(l<r&&v[r]>=t)r--;
        if(l<r)
            v[l++] = v[r];
    }
    v[l] = t;
    
    sort(begin,l-1);
    sort(l+1,end);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    sort(0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    return 0;
}
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;
int v[N];
int n;

void Q_sort(int a[],int begin,int end){
    if(begin>=end)return;
    int l = begin-1, r = end+1,x = a[begin + end >> 1];
    while(l<r){
        while(a[++l]<x);//������++l��--r��Ȼ ���l��r������x��l<r,�ͻ������ѭ�� 
        while(a[--r]>x);
        //cout<<"$$$$$$$$$$"<<l<<' '<<r<<' '<<x<<endl;
        if(l<r)swap(a[l],a[r]);
		//for(int i=0;i<n;i++)
    	//cout<<v[i]<<' ';cout<<endl;
    }
    
	 
    Q_sort(a,begin,r);
    Q_sort(a,r+1,end);
}

int main(){
    //int n; 
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    Q_sort(v,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    return 0;
}
//*/
