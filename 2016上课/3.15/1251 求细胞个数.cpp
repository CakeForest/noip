#include<stdio.h>
int sum=0;
int n,m,nowx,nowy,movex[4]={0,0,1,-1},movey[4]={1,-1,0,0};
int map[30][30]={0},qx[30],use[30][30]={0},qy[30],top,rear;

int main()
{

	scanf("%d %d",&n,&m);
	char c;
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c=getchar();
			if(c!='0')
				map[i][j]=1;
		}
		getchar();
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(map[i][j]==1)
			{
				map[i][j]=0;
				rear=1;top=0;
				qx[0]=i;qy[0]=j;
				do{
					for(int z=0;z<=3;z++)
					{
						nowx=qx[top]+movex[z];
						nowy=qy[top]+movey[z];
						if(map[nowx][nowy]==1)
						{
							map[nowx][nowy]=0;
							qx[rear]=nowx;
							qy[rear]=nowy;
							rear++;
						}
					}
					top++;
				}while(rear!=top);
				sum++;
			}
			
	printf("%d",sum);

	
	return 0;
}
