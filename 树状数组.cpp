#include <stdio.h>
#include <memory.h>
using namespace std;
const int max=500005;
int a[max],Tree[max],m,n;
int lowbit(int x){
	return x&(-x);
}
void modify(int index,int val){
	/*
	for(int i=1;i<=n;i++){
		printf("%d ",Tree[i]);
	} 
	printf("TreeBefore\n"); 
	*/ 
	for(int i=index;i<=n;i+=lowbit(i))
	{
		Tree[i]+=val;
	}
	/*
	for(int i=1;i<=n;i++){
		printf("%d ",Tree[i]);
	} 
	printf("Tree\n");
	*/
}
int get(int index){
	int ans=0;
	for(int i=index;i;i-=lowbit(i))
		ans+=Tree[i];
	return ans;
}
int main()
{ 
	memset(Tree,0,sizeof(Tree));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		modify(i,a[i]);
	}
	
	for(int j=1;j<=m;j++){
		int Case,idx,num;
		scanf("%d %d %d",&Case,&idx,&num);
		if(Case==1){
			modify(idx,num);
		}
		else if(Case==2){
			printf("%d\n",get(num)-get(idx-1));
		}
	}
	return 0;
} 
