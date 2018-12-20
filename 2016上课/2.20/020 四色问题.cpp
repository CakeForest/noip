#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,map[10][10],ans=0,color[9]={0};
void hs(int t)
{
	if(t>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=4;i++)//ËÄÖÖÑÕÉ« 
	{
		int flag=1;
		for(int j=1;j<t;j++)
			if(color[j]==i&&map[t][j]==1)
			{
				flag=0;
				break;
			}
		if(flag)
		{
			color[t]=i;
			hs(t+1);
		}
	}
	
	
}
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	hs(1);
	printf("%d",ans);
	return 0;
}
