#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5+5;
int a[N],b[N];

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
        
    int i=0,j=m-1;
    while(i<n && j>=0){
        //如果不够则i++
        if(a[i]+b[j]<k)i++;
        else if(a[i]+b[j]>k)j--;
        else {
            printf("%d %d\n",i,j);
            i++;
        }
    }
    
    return 0;
}
