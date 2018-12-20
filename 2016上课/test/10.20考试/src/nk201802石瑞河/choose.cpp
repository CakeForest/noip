#include<iostream>   
#include<algorithm>   
#include<cstring>
#include<cstdlib>   
#include<cstdio>   
#include<vector>   
#include<cmath>   
#include<queue>   
#define LL  long long  
using namespace std;
const int maxn=200000+10;
void du(LL &d)
{
	char t=getchar();  bool mark=false;
	for(;t<'0'||t>'9';t=getchar())if(t=='-')mark=!mark;
	for(d=0;t>='0'&&t<='9';t=getchar())d=d*10+t-'0';
	if(mark==true)d=-d;
}
LL n,m;
LL a[maxn]; 
LL b[maxn];
LL f[5][maxn/2];
LL g[5][maxn/2];
const LL INF=100000;
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	du(n);du(m);
	if((n/2)<m)
	{
		printf("Error!");
		return 0;
	}
	LL i,j,ans=-INF;
	for(i=1;i<=n;i++)du(a[i]);
	for(i=1;i<n;i++)b[i]=a[i+1];
	
	LL p=n/2+1;
	for(i=0;i<=4;i++)
	   for(j=0;j<=p;j++)f[i][j]=g[i][j]=-INF;
	
	f[1][1]=a[1];
	f[2][1]=max(a[1],a[2]);
	
	for(i=3;i<n;i++)
	{
		for(j=1;j<i&&j<=m;j++)
		{
			f[i&3][j]=max(f[(i-1)&3][j],f[(i-2)&3][j-1]+a[i]);	
		}
	}
	if(f[(n-1)&3][m]>ans)ans=f[(n-1)&3][m];

	g[1][1]=b[1];
	g[2][1]=max(b[1],b[2]);
	for(i=3;i<n;i++)
	{
		for(j=1;j<i&&j<=m;j++)
		{
			g[i&3][j]=max(g[(i-1)&3][j],g[(i-2)&3][j-1]+b[i]);
		}
		
	}
	if(g[(n-1)&3][m]>ans)ans=g[(n-1)&3][m];
	cout<<ans;
}
