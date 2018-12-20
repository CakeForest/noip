#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m;
	char g[120][120];
	scanf("%d %d",&n,&m);
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			char a=getchar();
			if(a!='\n')
				g[x][y]=a;
			else 
				y--;
		}
	}//载入地图 
	
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=m;y++)
		{
			if(g[x][y]=='*')
				printf("*");
			else
			{
				int sum=0;
				for(int px=x-1;px<=x+1;px++)
				{
					for(int py=y-1;py<=y+1;py++)
					{
						if(px!=0&&py!=0&&px!=n+1&&py!=m+1)
						{
							if(g[px][py]=='*')
								sum++;
						}
					}
				}
				printf("%d",sum);
			}
		}
		if(x!=n)
			printf("\n");
	}//算出地雷数 
	
	
	return 0;
}
