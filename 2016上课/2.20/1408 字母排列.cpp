#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n,flag[50]={0},log[50];
void hs(int t)
{
	if(t>n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%c",log[i]+'A'-1);
			if(i==n)
				printf("\n");
			 
		}
		return;//此处非常重要
	}
	for(int i=1;i<=m;i++)
		if(flag[i]==0)
		{
			flag[i]=1;
			log[t]=i;
			hs(t+1);
			flag[i]=0;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d %d",&m,&n);
	hs(1);	
	return 0;
}
