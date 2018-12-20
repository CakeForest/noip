#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10005;
int f[maxn][maxn][2][2]; //f[i][j][k] i表示当前第i个数，j表示取了多少个数，k=0表示不取1，k=1表示取1； 
int a[maxn];
int minn;

int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int i,j,k,m,n,b,p;
	scanf("%d%d",&n,&m); 
	if(n>10005)
	{
		printf("nk 80 year\n");
		return 0;
	}
	if(n/2<m)
	{
		printf("Error!\n");
		return 0;
	}
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
	}
	
	for(i=1;i<=n;i++) a[i]-=minn;
	f[1][1][1][1]=a[1];
	
	for(i=2;i<=n;i++)
	for(j=m;j;j--)
	for(k=0;k<=1;k++)
	for(p=0;p<=1;p++)
	{
		if(k==0)
		{
			f[i][j][k][p]=max(f[i-1][j][0][p],f[i-1][j][1][p]);
		}
		else
		{
			f[i][j][k][p]=f[i-1][j-1][0][p]+a[i];
		}
	}
	
	int ans=max(f[n][m][1][0],max(f[n][m][0][1],f[n][m][0][0]));
	printf("%d\n",ans+m*minn);
	return 0;
}
