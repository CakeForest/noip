#include<cstdio>

int x,y,flag=0,log_x[30],log_y[30],map[30][30]={0};
int move_x[8]={-2,-2,-1,-1,1,1,2,2},move_y[8]={-1,1,-2,2,-2,2,-1,1};
void hs(int t,int now_x,int now_y)
{
	if(flag)
		return;
	if(t>x*y)
	{
		flag=1;
		return;
	}
	for(int i=0;i<=7;i++)
	{
		int x2,y2;
		x2=now_x+move_x[i];
		y2=now_y+move_y[i];
		if(x2>=1&&x2<=x&&y2>=1&&y2<=y&&map[x2][y2]==0)
		{
			map[x2][y2]=1;
			log_x[t]=x2;
			log_y[t]=y2;
			hs(t+1,x2,y2);
			map[x2][y2]=0;
		}
	}
	
}
int main()
{
	freopen("in.txt","r",stdin);
	int n,input[2][30];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&input[0][i],&input[1][i]);
	for(int i=1;i<=n;i++)
	{
		printf("Scenario #%d:\n",i);
		x=input[0][i]; y=input[1][i];
		log_x[1]=1;
		log_y[1]=1;
		map[1][1]=1;
		hs(2,1,1);
		map[1][1]=0;
		if(flag)
			for(int j=1;j<=x*y;j++)
				printf("%c%d",'A'+log_y[j]-1,log_x[j]);
		else
			printf("impossible");
		flag=0;
		if(i!=n)
			printf("\n\n");
		else
			printf("\n");
	}

	
	return 0;
}
