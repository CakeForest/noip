#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,m;
	int w[20020];
	int wi[20020];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&wi[i]);	
	
	int i=0;
	int p=1;
	while(1)
	{
		for(int k=1;k<=m;k++)
			if(w[k]==0)//如果有人接完了水，就换下一个人 
			{
				if(p==n)//人都开始接水的时候计算接的最慢的人所需的时间 
				{
					w[k]=wi[p];
					int max=-1;
					for(int z=1;z<=m;z++)
						if(w[z]>max)
							max=w[z];
					i+=max;
					printf("%d",i);
					return 0;
				}
				else
				{
					w[k]=wi[p];
					p++;					
				}

			}
		for(int k=1;k<=m;k++)
			w[k]--;
		i++;
	}
	
	return 0;
}