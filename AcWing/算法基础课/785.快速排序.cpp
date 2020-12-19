/*
//这个会超时
#include <iostream>
#include <cstdio>
using namespace std;

int n;
int v[100005];
void sort(int begin,int end){
    if(begin>=end)return;
    int t = v[end],l = begin, r = end;
    while(l<r){
        //从右边找出小于标准的第一个数
        while(l<r&&v[l]<=t)l++;
        if(l<r)
            v[r--] = v[l];
        //从右边找到小于标准的第一个数
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
        while(a[++l]<x);//必须是++l和--r不然 如果l和r都等于x，l<r,就会出现死循环 
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
