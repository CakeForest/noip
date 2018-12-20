#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[300],b[300],ans[1000];
int work(int n,bool t)//n输入的字符（数字） t是否转换成数字 
{//字符与数字的转换函数 
	if(t==1)
		return n-'0';
	else
		return '0'+n;
}

int main()
{
	char c[300];
	int len_a,len_b;
	gets(c);
	len_a=strlen(c);
	for(int i=len_a;i>=1;i--)
		a[len_a-i]=work(c[i-1],1);//以倒序整型读入两个数
	gets(c);
	len_b=strlen(c);	
	for(int i=len_b;i>=1;i--)
		b[len_b-i]=work(c[i-1],1);
	
	int ji;	//对两个数进行操作，但不进位，保存在ans[]中 
	for(int i=0;i<=len_a-1;i++)
		for(int j=0;j<=len_b-1;j++)
		{
			ji=a[i]*b[j];
			ans[i+j+1]+=ji/10;
			ans[i+j]+=ji%10;//此处累赘，可以不用进位，到最后一同进位 
		}
	
	int j=0,log;
	while(j<=len_a+len_b-2)//进位操作 
	{
		log=ans[j];
		if(log>=10)
		{
			ans[j]=log%10;
			ans[j+1]+=log/10;
		}
		j++;
	}
	/*if(ans[len_a+len_b-2]==0)
		j--;*/
	while(ans[j]==0&&j>=0)
		j--;
	if(j==-1)
		j++;
	for(int i=j;i>=0;i--)//输出数字
		printf("%c",work(ans[i],0));
	
	return 0;
}
