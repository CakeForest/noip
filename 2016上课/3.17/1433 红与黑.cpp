#include<stdio.h>
using namespace std;
const int MAXSIZE=30;

struct node{
	int x,y;
}queue[MAXSIZE*MAXSIZE];
int top,rear,map[MAXSIZE][MAXSIZE]={0};
int movex[4]={0,0,1,-1},movey[4]={1,-1,0,0};
int sum=1;
node start;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	char c;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c=getchar();
			if(c=='.')
				map[i][j]=1;
			else if(c=='@')
			{
				start.x=i;
				start.y=j;
			}
		}
		getchar();
	}
	
	queue[0].x=start.x;
	queue[0].y=start.y;
	top=0;rear=1;
	do{
		node now,next;
		now.x=queue[top].x;
		now.y=queue[top].y;
		for(int z=0;z<=3;z++)
		{
			next.x=now.x+movex[z];
			next.y=now.y+movey[z];
			if(map[next.x][next.y]==1)
			{
				map[next.x][next.y]=0;
				queue[rear].x=next.x;
				queue[rear].y=next.y;
				sum++; rear++;
			}
		}
		top++;
	}while(top!=rear);
	printf("%d",sum);

	
	return 0;
}
