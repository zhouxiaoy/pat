#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void f(char* buf, unsigned char* uckey, int n)
{

	int i;
	for(i=0; i<n; i++)
		buf[i] = buf[i] ^ uckey[i];    //������㣬����buf[i] ^= uckey[i]
}

int main(int argc, char* argv[])
{
	char p[] = "abcd�й���123";  // �����ܴ�

	char* key = "11001100010001110";  //�Դ�����ʽ�����ܳף�����ʱҪת��Ϊ��λ�洢����ʽ��

	int np = strlen(p);
	int nk = strlen(key);
	unsigned char* uckey = (unsigned char*)malloc(np);  // unsigned char���޷����ֽ��ͣ�char���ͱ����Ĵ�Сͨ��Ϊ1���ֽڣ�1�ֽ�=8��λ��	
	// �ܳ״���Ҫ��λ����ʽѭ��ƴ�� uckey��
	int i;
	
	for(i=0; i<np*8; i++)
	{
		if(key[i%nk]=='1')
			uckey[i/8] |= (unsigned char)0x80 >> (i%8);  // ���1��λ��
		else
			uckey[i/8] &= ~((unsigned char)0x80 >> (i%8));  // ���2��λ��
	}
	
	f(p, uckey, strlen(p));
	printf("%s\n", p);
	f(p, uckey, strlen(p));

	printf("%s\n", p);

	free(uckey);

	return 0;
}




