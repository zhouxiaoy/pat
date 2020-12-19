#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void f(char* buf, unsigned char* uckey, int n)
{

	int i;
	for(i=0; i<n; i++)
		buf[i] = buf[i] ^ uckey[i];    //异或运算，即：buf[i] ^= uckey[i]
}

int main(int argc, char* argv[])
{
	char p[] = "abcd中国人123";  // 待加密串

	char* key = "11001100010001110";  //以串的形式表达的密匙，运算时要转换为按位存储的形式。

	int np = strlen(p);
	int nk = strlen(key);
	unsigned char* uckey = (unsigned char*)malloc(np);  // unsigned char是无符号字节型，char类型变量的大小通常为1个字节（1字节=8个位）	
	// 密匙串需要按位的形式循环拼入 uckey中
	int i;
	
	for(i=0; i<np*8; i++)
	{
		if(key[i%nk]=='1')
			uckey[i/8] |= (unsigned char)0x80 >> (i%8);  // 填空1按位或
		else
			uckey[i/8] &= ~((unsigned char)0x80 >> (i%8));  // 填空2按位与
	}
	
	f(p, uckey, strlen(p));
	printf("%s\n", p);
	f(p, uckey, strlen(p));

	printf("%s\n", p);

	free(uckey);

	return 0;
}




