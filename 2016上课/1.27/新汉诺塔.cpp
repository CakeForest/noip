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
	if(now==0)//���������С����ôֱ���ƶ� 
		return;
	if(a!=b)//�����������Ҫ�ƶ�����ִ�� 
	{
		hnt(now-1,start[now-1],c,through(start[now-1],c));//��n-1���Ƶ�c�� 
		start[now]=b;//���������Ƶ�Ŀ��λ�� 
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
