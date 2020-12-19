#include <iostream>
#include <algorithm> 
using namespace std;
typedef struct tagTask{
	int taskID;
	int RO;
}STask;
static bool Compare(const tagTask& t1,const tagTask& t2){
		return t1.RO>t2.RO;
	}
bool IsTaskable(int N,int M,const int* R,const int * O){
	STask* st = new STask[N];
	int i;
	for(i=0;i<N;i++){
		st[i].taskID = i;
		st[i].RO = R[i]-O[i]; 
	}
	sort(st,st+N,Compare);
	int occupy =0;
	bool bOK = true;
	int k;
	for(i=0;i<N;i++){
		k= st[i].taskID;
		if(occupy + R[k]> M){
			bOK = false;
			break;
		}
		occupy +=O[k];
	}
	delete [] st;
	return bOK;
}
int main(){
	const int N=2;//任务数目
	const int M=14;//内存数目
	int R[N]={10,8}; 
	int O[N]={5,6};
	bool b = IsTaskable(N,M,R,O);
	cout<<(b?"Yes\n":"No\n");
	return 0;
} 
