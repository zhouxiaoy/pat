#include <iostream>
#include <cmath>
using namespace std;
const int N = 55;
int q[N];
int main(){
    int n;
    cin>>n;
    int left = 0,right = 0;//left��ʾ��ð���ϵ���ߺ��������෴��������������߷�����ͬ������ײ��
    //right��ʾ��ð���ϵ��ұߺ���������ͬ����������
    cin>>q[0];
    for(int i=1;i<n;i++){
        cin>>q[i];
        //��ð������������
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
