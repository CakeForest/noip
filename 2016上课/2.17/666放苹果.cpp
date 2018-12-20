#include<stdio.h>
#include<stdlib.h>

int m[30],n[30],a[100],sum=0,p;
void work(int left,int now)
{
	
	
	
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
		sum=0;
		work(m[i],1);
		printf("%d",sum);
		if(i!=t)
			printf("\n");
	}
	
}
