#include<stdio.h>
#include<stdlib.h>

int m[30],n[30],a[100]={0},k=0,p,sum;
void work(int left,int now)
{
	if(now==p)
	{
		if(left>=a[now-1])
			k++;
		return;
	}
	for(int i=a[now-1];i<=left/2;i++)
	{
		a[now]=i;
		work(left-i,now+1);
	}
	
	
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		scanf("%d %d",&m[i],&n[i]);//M个苹果,N个盘子
	for(int i=1;i<=t;i++)
	{
		p=n[i];
		k=0;
		work(m[i],1);
		printf("%d",k);
		if(i!=t)
			printf("\n");
	}
	
}
