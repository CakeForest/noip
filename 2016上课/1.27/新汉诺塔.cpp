#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int start[100],end[100],sum=0;
int through(int a,int b)
{
	for(int i=1;i<=3;i++)
		if(a!=i&&b!=i)
			return i;
}

void hnt(int now,int a,int b,int c)
{
	if(now==0)//如果盘子最小，那么直接移动 
		return;
	if(a!=b)//如果此盘子需要移动，则执行 
	{
		hnt(now-1,start[now-1],c,through(start[now-1],c));//将n-1盘移到c柱 
		start[now]=b;//将大盘子移到目标位置 
		printf("move %d from %c to %c\n",now,a+'A'-1,b+'A'-1);
		sum++;
	}
	hnt(now-1,start[now-1],end[now-1],through(start[now-1],end[now-1]));
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
	{
		int m;
		scanf("%d",&m);
		for(int t=1;t<=m;t++)
		{
			int k;
			scanf("%d",&k);
			start[k]=i;
		}
	}
	for(int i=1;i<=3;i++)
	{
		int m;
		scanf("%d",&m);
		for(int t=1;t<=m;t++)
		{
			int k;
			scanf("%d",&k);
			end[k]=i;
		}
	}
	hnt(n,start[n],end[n],through(start[n],end[n]));
	printf("%d",sum);
	
	return 0;
}
