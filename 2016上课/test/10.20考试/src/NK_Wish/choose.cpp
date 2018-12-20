#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200006
using namespace std;
int n,m;
int a[maxn],b[maxn];
int f[4][maxn][2];
int s,t;
int ans=0;
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&s);
	for(int i=1;i<=n-2;i++){scanf("%d",&a[i]);b[n-2-i+1]=a[i];}
	scanf("%d",&t);
	if(n/2<m){printf("Error!");return 0;}
	
	f[1&1][1][1]=a[1];
	f[1&1][0][0]=0;
	f[0&1][0][0]=0;
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=(i,m);j++)
		{
			f[i&1][j][0]=max(max(f[i&1][j][0],f[(i-1)&1][j][1]),f[(i-1)&1][j][0]);
			f[i&1][j][1]=f[(i-1)&1][j-1][0]+a[i];	
		}
	/*for(int i=1;i<=n;i++)
	{
	cout<<i<<" "<<" "<<f[i][m][0]<<" "<<f[i][m][1]<<endl;
	}*/
	ans=max(max(max(f[(n-2)&1][m-1][0]+t,f[(n-2)&1][m][0]),f[(n-2)&1][m][1]),ans);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=min(i,m);j++)
		{
			f[i&1][j][0]=max(max(f[i&1][j][0],f[(i-1)&1][j][1]),f[(i-1)&1][j][0]);
			f[i&1][j][1]=f[(i-1)&1][j-1][0]+b[i];	
		}
	ans=max(max(max(f[(n-2)&1][m-1][0]+s,f[(n-2)&1][m][0]),f[(n-2)&1][m][1]),ans);
	
	cout<<ans;
}
		
	
	
