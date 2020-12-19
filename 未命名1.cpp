#include<iostream>
#include <cstdio>
using namespace std;
int ans[1010],tot=0;
bool vis[1010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ans[i];
    
    for(int i=1;i<=n-2;i++){
    	for(int j=i+1;j<=n-1;j++){
    			if(vis[j]==true||ans[k]<=ans[j])continue;
    		for(int k = j+1;k<=n;k++){
    			if(ans[k]>ans[j]&&ans[j]>ans[i]&&vis[j]==false)
    				{
    					tot++;
    					vis[j] = true;
					}
			}
    	}
	}
	cout<<tot;
	return 0;
}
