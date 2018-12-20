#include<stdio.h>
int ans[30]={0},map[10][10],ans_i=1,use_x[10]={0},use_y[10]={0},n,k;
void hs(int t,int x,int y)//ÌîµÚt¸öÆå×Ó 
{
	if(t>k)
	{
		ans[ans_i]++;
		return;
	}
	int flag=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(flag&&t!=1)
			{
				flag=0;
				i=y%4==0?x+1:x;
				j=y%4==0?1:y+1;
			}
			if(map[i][j]==0&&use_x[j]==0&&use_y[i]==0)
				{
					map[i][j]=1;
					use_x[j]=1;
					use_y[i]=1;
					flag=1;
					hs(t+1,i,j);
					map[i][j]=0;
					use_x[j]=0;
					use_y[i]=0;
				} 
		} 
	
}
int main()
{
	freopen("in.txt","r",stdin);
	char input;
	while(1)
	{
		scanf("%d %d",&n,&k);
		if(n==-1&&k==-1)
			break;
		getchar();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%c",&input);
				if(input=='.')
					map[i][j]=1;
				else
					map[i][j]=0;
			}
			getchar();
		}
		hs(1,0,0);
		ans_i++;
		for(int i=1;i<=10;i++)
		{
			use_x[i]=0;
			use_y[i]=0;
		}
	}
	ans_i--;
	for(int i=1;i<=ans_i;i++)
		printf("%d\n",ans[i]);
	return 0;
}
