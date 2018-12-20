#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char a[10];
int print[10];//每个元素储存要输出的字符在a[]中的序号 
int use[1000]	;//记录每个元素是否被使用 
int len;
void pri()
{
	for(int i=0;i<=len-1;i++)
		printf("%c",a[print[i]]);
	printf("\n");
}

void work(int n)//n表示目前占用的字母个数  
{
	int i=0;
	for(int i=0;i<=len-1;i++)
	{
		if(use[i]==0)
		{
			use[i]=1;
			print[n]=i;
			work(n+1);
			use[i]=0;
		}
	}
		
	if(n==len-1)
		pri();
	return;
}

int main()
{
	scanf("%s",a);
	len=strlen(a);
	work(0);
}
