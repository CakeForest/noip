#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m;
	scanf("%d",&n);
	bool empty[120][120]={0};
	char room[120][120]={0};
	bool sick[120][120]={0};
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			char a=getchar();
			if(a!='\n')
				room[x][y]=a;
			else
				y--;
			if(a=='#')
				empty[x][y]=true; //读取空房间 
			if(a=='@')
				sick[x][y]=true;//读取病人 
		}
	}//读取房间
	scanf("%d",&m);
	



	for(int i=2;i<=m;i++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				if(empty[x][y]==false&&sick[x][y]==true)
				{
					room[x+1][y]='@';
					room[x-1][y]='@';
					room[x][y+1]='@';
					room[x][y-1]='@';
				}
			}
		}//传染 
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				if(room[x][y]=='@')
					sick[x][y]=true;
			}
		}//传染记录	
	}//模拟传染 
	
	
	
	int sum=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			if(room[x][y]=='@'&&empty[x][y]==false)
				sum++;
		}
	}//病人总数 
	printf("%d",sum);
	
	return 0;
}
