#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,movex[8]={-1,1,2,2,1,-1,-2,-2},movey[8]={2,2,1,-1,-2,-2,-1,1};
int ans=0,map[8][8]={0};
void hs(int t,int x,int y)
{
	if(t>n*m)
	{
		ans++;
		return;
	}
	for(int i=0;i<=7;i++)
	{
		int x2,y2;
		x2=x+movex[i];
		y2=y+movey[i];
		if(x2>=1&&x2<=n&&y2>=1&&y2<=m&&map[x2][y2]==0)
		{
			map[x2][y2]=1;
			hs(t+1,x2,y2);
			map[x2][y2]=0;
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	int x,y;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&x,&y);
	map[x][y]=1;
	hs(2,x,y);
	printf("%d",ans);
	return 0;
}
