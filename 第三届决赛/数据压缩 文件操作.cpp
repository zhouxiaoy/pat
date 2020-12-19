#include <stdio.h>
const int BUF_N = 100;
void pop(int s, int* buf, int c, FILE* fp)//s是标志位，如果是0，则表示前c位数都不一样，如果是1，则表示前c位数一样
{
	int i;
	if(s)//如果前c位数不一样，直接将c和buf的第一个数字输出到文件fp
	{
		fprintf(fp, "%d %d ", c, *buf);
	}
	else//如果前c位数一样，先输出-c，然后将每一位数输出
	{
		fprintf(fp, "%d ", -c);
		for(i=0; i<c; i++)
		{
			fprintf(fp, "%d ", buf[i]);
		}
	}
}
 
void dopack(FILE* r, FILE* w)//用来进行压缩的函数
{
	int buf[BUF_N];//文件缓冲数组，将文件中的内容一位一位的读取到这个数组当中
 
	int pos = 0;  // 下一个数字在buf中将要存放的位置
	int c = 0;    // 当前段已读入的整数个数
	int pst;      //前c个数是否是一样的
	int cst;      //刚读入的数字与之前读入的最后一个数是否一样，即buf[pos-1]==pos[pos]
 
	while(fscanf(r, "%d", buf+pos)==1)//从文件读入，注意，如果读到文件尾，则返回值为0
	{
		if(c==0)//读入第一个数时的操作
		{
			c = pos = 1;//读入的数量为1，并且下一个数要存到1这个位置上
			continue;//结束本次循环
		}
 
		if(c==1)//读入第二个数
		{
			pst = buf[0] == buf[1];//判断刚读入的这个数字和之前的数字是否一样
			pos = pos + 1 - pst;//如果一样，下一个读入的数字仍然存在pos这个位置，否则存到下一个位置
			c = 2;//读入的数量为2
			continue;//结束本次循环
		}
		
		cst = buf[pos-1] == buf[pos];//当读入的数量大于2时，首先判断刚读入的这个数与之前的那个数是否一样
		if(pst && !cst)//如果之前的c个数都一样并且刚读入的数与之前的数不一样
		{
			pop(pst, buf, c, w);//将数量c和重复的数字输出到文件
			buf[0] = buf[1];//因为刚读入的那个数字（buf[pos]）是不一样的，所以应该将它放到buf中的第一位，然后从第二个开始读
			c = pos = 1;//读入的数量为1，且下一个数应该存到buf的第一个位置
			pst = cst;//因为读到了不一样的数，所以标志位pst应该与刚才得到的cst相同，即表示前c个数不相同
		}
		else if(!pst && cst || pos == BUF_N-1)//如果前c个数不相同并且刚读入的数与之前的一个数相同，又或者buf已经满了
		{
			pop(pst, buf, c-1, w);//将数量c和前c-1个数输出到文件，因为第c个数和第c+1（即pos）个数是相同的，表示已经读入了两个相同的数，又或者是buf已经满了
			buf[0] = buf[pos-1];//将倒数第二个数字存到buf的第一个，再次从头开始读
			c = 2;//已经读入了两个相同的数字，或者虽然不相同，但是buf已经满了，为了处理上的一致性，同样保留读入的最后两个数字
 
			if(!cst)//如果前c个数是不一样的，由于buf满了
			{
				buf[1] = buf[pos];//将最后一个数字存到buf的第二个，因为是不同的数字
				pos = 2;//下一个数存到buf的第3个位置
			}
			else//如果是因为遇到相同的数
			{
				pos = 1;//下一个数存到1这个位置
				pst = cst;  // 填空1，因为是遇到了不同的数字，所以pst状态要改变，只要和cst一致就可以，因为cst表示的就是不一样的数
			}
		}
		else//如果哪种情况都不满足
		{
			c++;//让c++，即读入的数量加1
			if(!pst) pos++;//如果之前读入的数都一样，那么pos的位置不用变，只有不一样才要跳到下一个
		}
	} // while
 
	if(c>0) pop(pst,buf,c,w);   // 填空2，还记得吗，如果读到文件尾，那么循环直接就结束了，这就意味着buf中可能还有未被写到文件中的数据，可能是全都一样的数，也可能是全都不一样的数
}				    //这个是由pst决定的，所以只要再次把buf中的内容写到文件中就可以了
 
int main()
{
	FILE* rfp;
	FILE* wfp;
 	char RFILE[10] = "RFILE.txt";
	if((rfp=fopen(RFILE, "r")) == NULL)
	{
		printf("can not open %s!\n", RFILE);
		return 0; 
	}
 	char WFILE[10] = "WFILE.txt";
	if((wfp=fopen(WFILE, "w")) == NULL)
	{
		printf("can not open %s!\n", WFILE);
		fclose(rfp);
		return 0;
	}
 
	dopack(rfp, wfp);
 
	fclose(wfp);
	fclose(rfp);
	return 0;
}
