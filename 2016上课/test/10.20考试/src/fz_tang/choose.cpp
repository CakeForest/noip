#include<stdio.h>
#include<algorithm>
using namespace std;
int f[2][5003][5003]={0},pos[200005]={0};
struct bang {
	int po,v;
};
bang a[200008];
bool cmp(bang x,bang y)
{
	return x.v>y.v;
}
int max(int x,int y)
{
	if(x>y)
	return x;
	return y;
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m,i;
	scanf("%d%d",&n,&m);
	if(m*2>n)
	{
		printf("Error!");
	}
	else
	{
		long long total=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].v);
		}
		make_heap(a+1,a+n+1,cmp);
		sort_heap(a+1,a+n+1,cmp);
		for(i=1;i<=n;i++)
		{
			if(m<=0)
			{
				break;
			}
			int x=a[i].po+1,y=a[i].po-1;
			if(x>n)
			{
				x-=n;
			}
			if(y<=0)
			{
				y+=n;
			}
			if(pos[x]==0&&pos[y]==0)
			{
				pos[x]=-1;
				pos[y]=-1;
				total+=a[i].v;
				m--;
			}
		}
/*		for(i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%5d %5d  ",f[0][i][j],f[1][i][j]);
			}
			printf("\n");
		}
*/		printf("%d",total);
	}
	return 0;
}
