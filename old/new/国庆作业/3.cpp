#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int k[50][50]={0};
	int x,y;
	for(int i=1;i<=4*n*n-4*n+1;i++)
	{
		if(i==1)
		{
			x=1;
			y=n;
			k[x][y]=i;			
		}
		else
		{
			if(x==1&&y!=2*n-1)
			{
				x=2*n-1;
				y+=1;
				k[x][y]=i;
			}
			else if(x!=1&&y==2*n-1)
			{
				x-=1;
				y=1;
				k[x][y]=i;
			}
			else if((x==1&&y==2*n-1)||(k[x-1][y+1]!=0))
			{
				x+=1;
				k[x][y]=i;				
			}
			else
			{
				x-=1;
				y+=1;
				k[x][y]=i;					
			}
		}
	}//构造幻方 
	
	for(int x=1;x<=2*n-1;x++)
	{
		for(int y=1;y<=2*n-1;y++)
		{
			printf("%d",k[x][y]);
			if(y!=2*n-1)
				printf(" ");
		}
		if(x!=2*n-1)
			printf("\n");
	}//输出幻方 
	
	return 0;
}
