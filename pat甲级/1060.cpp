//���µ���Ŀ �������Ĵ����ַ����� 


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int getPosition(string a){
    int t = -1;
    for(int i=0;i<a.size();i++)
	    if(a[i] == '.'){
	        t = i;break;
	    }
	return t;
}

int main(){
	int n; 
	string a,b;
	cin>>n>>a>>b;
	int dec_a,dec_b;//С�����λ��
	dec_a = getPosition(a);//Ҳ����ֱ����find����
	dec_b = getPosition(b);
	
	int t1 = 0,t2 = 0;
	
	if(dec_a != -1) t1 = a.size()-dec_a - 1, a.erase(dec_a,1);
	if(dec_b != -1) t2 = b.size()-dec_b - 1, b.erase(dec_b,1);
	//cout<<t1<<' '<<t2<<endl;
	
	if (t1 > t2)
	    b.insert(b.size()-1, t1 - t2, '0');
	else if(t1 < t2)
	    a.insert(a.size()-1, t2 - t1, '0');
	cout<<a<<' '<<b<<endl;
	bool flag = true;
	if(a.size() != b.size())flag = false;
	for(int i=0;i<n;i++){
	    if(a[i]!=b[i]){
	        flag = false;
	        break;
	    }
	}
	if(flag)
	    printf("YES 0.");
	else printf("NO 0.");
	for(int i=0;i<n;i++)
	   if(i<b.size())
	        printf("%c",b[i]);
	   else
	        printf("0");
	printf("*10^%d",a.size() - max(t1,t2));
	
	if(!flag){
	printf(" 0.");
	for(int i=0;i<n;i++)
	   if(i<b.size())
	        printf("%c",b[i]);
	   else
	        printf("0");
	printf("*10^%d",b.size() - max(t1,t2));
	}
	return 0;
} 

//���ϵıȽ��������� 
/*
#include<bits/stdc++.h>
using namespace std;
int f(const string&s,string&temp,int N){//���ַ���s��Nλ��Ч���ִ洢���ַ���temp�У�������ָ��
    int point=s.size(),index=-1;//pointָʾ�ַ���s��С�����λ�ã���ʼ��Ϊ�ַ���s���һλ��indexָʾs�е�һλ�������ֵ�λ�ã���ʼ��Ϊ-1
    for(int i=0;i<s.size();++i)//�����ַ���s
        if(s[i]=='.')//�ҳ�С����λ��
            point=i;
        else if(index!=-1&&temp.size()<N)//��s�����Nλ��Ч���ִ洢��temp��
            temp+=s[i];
        else if(index==-1&&s[i]!='0'){//�ҵ��ַ���s��һλ�������ֵ�λ��
            index=i;
            temp+=s[i];
        }
    while(temp.size()<N)//temp����С��N������Ч����λ��С��N
        temp+="0";//���ַ���ĩβ���㹻��0��֤��Nλ��Ч����
    if(index==-1)//û���ҵ��������֣�˵���ַ���s��ʾ������0
        return 0;//ָ��Ϊ0������
    point-=index;//С����λ�ü�ȥ��һλ��������λ�õõ�ָ��
    return point<0?point+1:point;//��ǰpointΪ����������point+1�����򷵻�point
}
int main(){
    int N;
    string A,B,Atemp="",Btemp="";
    cin>>N>>A>>B;//��ȡ����
    int Aexp=f(A,Atemp,N),Bexp=f(B,Btemp,N);//�õ���Ч���ֺ�ָ��
    if(Aexp==Bexp&&Atemp==Btemp)//��Ч���ֺ�ָ�������
        cout<<"YES 0."<<Atemp<<"*10^"<<Aexp;//������ȣ����YES�Ϳ�ѧ���㷨��ʾ���ַ���
    else//�������NO�Ϳ�ѧ���㷨��ʾ���ַ���
        cout<<"NO 0."<<Atemp<<"*10^"<<Aexp<<" 0."<<Btemp<<"*10^"<<Bexp;
    return 0;
}
*/ 
