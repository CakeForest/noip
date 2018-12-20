#include<cstdio>
using namespace std;
const int MAXSIZE=1020;
int qx[MAXSIZE*MAXSIZE],qy[MAXSIZE*MAXSIZE],qsum[MAXSIZE*MAXSIZE];
int map[MAXSIZE][MAXSIZE]={0},top,rear;
int movex[4]={0,0,-1,1},movey[4]={-1,1,0,0};///´Ë´¦Ôø¾­´íÎó 
int n,startx,starty,endx,endy,nowx,nowy,ans;
int nextx,nexty;

int main()
{
	scanf("%d",&n);
	char c;
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c=getchar();
			if(c=='0')
				map[i][j]=1;
		}
		getchar();
	}
	
	scanf("%d%d",&startx,&starty);
	scanf("%d%d",&endx,&endy);
	
	top=0;rear=1;
	qx[0]=startx;qy[0]=starty;
	qsum[0]=0;
	do{
		nowx=qx[top]; nowy=qy[top];
		if(nowx==endx&&nowy==endy)
		{
			ans=qsum[top];
			break;
		}
		else
		{
			map[nowx][nowy]=0;
			for(int z=0;z<=3;z++)
			{
				nextx=nowx+movex[z];
				nexty=nowy+movey[z];
				if(map[nextx][nexty]==1)
				{
					map[nextx][nexty]=0;
					qx[rear]=nextx;
					qy[rear]=nexty;
					qsum[rear]=qsum[top]+1;
					rear++;
				}
			}
		}
		top++;
	}while(top!=rear);
	printf("%d",ans);
	return 0;
}
