#include<cstdio>
using namespace std;
int map[6][6]={0},work[6][6]={0};
int movex[5]={0,0,0,1,-1},movey[5]={0,1,-1,0,0},flag=0;
int sum,ans=9999999;
void flip(int x,int y)//x为第几行 y为第几列
{
	sum++;
	for(int i=0;i<=4;i++)
	{
		int nextx=x+movex[i];
		int nexty=y+movey[i];
		if(nextx>=1&&nextx<=4&&nexty>=1&&nexty<=4)
			work[nextx][nexty]=work[nextx][nexty]==1?2:1;
	}
} 

int judge(int aim)
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(work[i][j]!=aim)
				return -1;
	return 1;
}

void hs(int now,int aim)
{
	if(now>=5||flag==1)
		return;
	if(judge(aim)==1)
		flag=1,ans=sum<ans?sum:ans;
	for(int i=1;i<=4;i++)
		if(work[now-1][i]!=aim)
			flip(now,i);
	hs(now+1,aim);
}

void Arraycpy()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			work[i][j]=map[i][j];
}

void Mapprint()
{
	printf("NOW MAP\n");
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
			printf("%d",work[i][j]);
		printf("\n");
	}
	printf("\n");	
}

int main()
{
	freopen("in.txt","r",stdin);
	char c;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			c=getchar();
			if(c=='w')
				map[i][j]=1;
			else if(c=='b')
				map[i][j]=2;
		}
		getchar();
	}
	
	for(int a=0;a<=1;a++)
		for(int b=0;b<=1;b++)
			for(int c=0;c<=1;c++)
				for(int d=0;d<=1;d++)
				{
					Arraycpy();
					sum=0;flag=0;
					if(a) flip(1,1);
					if(b) flip(1,2);
					if(c) flip(1,3);
					if(d) flip(1,4);
					hs(2,1);
					
					Arraycpy();
					sum=0;flag=0;
					if(a) flip(1,1);
					if(b) flip(1,2);
					if(c) flip(1,3);
					if(d) flip(1,4);
					hs(2,2);
				}
	if(ans==9999999)
		printf("Impossible");
	else
		printf("%d",ans);
	
	return 0;
}
