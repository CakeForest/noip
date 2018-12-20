#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct file
{
	char str[40];
};

bool cmp(file a,file b)
{
	return strcmp(a.str,b.str)<0;
}

int i=0;
char a[1000][40];
void pri(int n)//填空 
{
	for(int j=1;j<=n;j++)
		printf("|     ");
}

void work(int t)//处理单个文件结构 
{
	file f[100];//保存的文件名 
	int num=1;
	while(a[i][0]!='*'&&a[i][0]!=']')
	{
		if(a[i][0]=='d')
		{
			pri(t+1);
			printf("%s\n",a[i]);
			i++;
			work(t+1);//递归处理文件夹 
			
		}
		else if(a[i][0]=='f')
		{
			strcpy(f[num].str,a[i]);
			i++;
			num++;
		}
		
	}
	num--;
	if(a[i][0]==']')i++;//此处很关键！！ *****************************
	sort(f+1,f+1+num,cmp);//快速排序文件 


	for(int j=1;j<=num;j++)//处理完文件夹后输出文件 
	{
		pri(t);
		printf("%s\n",f[j].str);
	}	
	return;
	
}

int main()
{
//	freopen("in.txt","r",stdin);
	do{
		i++;
		scanf("%s",a[i]);
	}while(a[i][0]!='#');//读入所有数据 
	/*
	for(int j=1;j<=i;j++)
		printf("%d:%s\n",j,a[j]);
	printf("--------\n");
	*/
	i=1;
	int sum=1;
	while(a[i][0]!='#')//多个文件结构分别处理 
	{
		
		if(i!=1)
			printf("\n");
	//	printf("%d %d\n",sum,i);
		printf("DATA SET %d:\nROOT\n",sum);
		work(0);
		i++;
		sum++;
	}
	

	
	return 0;
}
