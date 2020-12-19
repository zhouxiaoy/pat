#include <iostream>
#include <cmath>
using namespace std;
const int N = 55;
int q[N];
int main(){
    int n;
    cin>>n;
    int left = 0,right = 0;//left表示感冒蚂蚁的左边和它方向相反的蚂蚁数量（左边方向相同不会相撞）
    //right表示感冒蚂蚁的右边和它方向相同的蚂蚁数量
    cin>>q[0];
    for(int i=1;i<n;i++){
        cin>>q[i];
        //感冒的蚂蚁向左走
        if(q[0]<0){
            if(q[i]*q[0]<0 && abs(q[i])<abs(q[0]))left++;
            else if(q[i]*q[0]>0 && abs(q[i])>abs(q[0]))right++;
        }else{
            if(q[i]*q[0]<0 && abs(q[i])>abs(q[0]))right++;
            else if(q[i]*q[0]>0 && abs(q[i])<abs(q[0]))left++;
        }
    }
    if(q[0]<0&&left==0)right = 0;
    else if(q[0]>0&&right == 0)left = 0;
    cout<<left+right+1;
    return 0;
}
