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
        if(vis[st[j]]==false){//在当前数字中该数字没出现过
            vis[st[j]] = true;
            j++;
        }else{//如果该数字重复出现
            maxlength  = max(maxlength,j-i);
            while(st[i]!=st[j]){
                vis[st[i]] = false;//将之前的清零
                i++;
            }
            //cout<<maxlength<<"之前的位置："<<i<<' '<<j;
            i++;//找到之后再往前移一位
            j++;
            //cout<<"现在的位置"<<i<<' '<<j<<endl;
        }
    }
    maxlength = max(maxlength,j-i);
    printf("%d\n",maxlength);
    return 0;
}
