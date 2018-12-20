#include<stdio.h>
#include<stdlib.h>
#include<cstring>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	bool light[5100]={0};
	
	for(int i=1;i<=m;i++)
	{
		for(int now=1;now<=n;now++)
		{
			if(now%i==0)
			{
				if(light[now]==1)
					light[now]=0;
				else
					light[now]=1;
			}
		}
	}
	

	int last;
	for(int i=n;i>=1;i--)
	{
		if(light[i]==1)
		{
			last=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(light[i]==1)
		{
			printf("%d",i);
			if(last!=i)
			{
				printf(",");
			}
		}
		
	}
	

	
	
	
	
	
	
	return 0;
}
