#include<cstdio>
#include<cstring>
#define max(a,b)((a)>(b)?a:b)
#define min(a,b)((a)<(b)?a:b)
using namespace std;
int n,m,b,r=100000007,a[200010],f[400010][2];
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d",&n,&m);
	if((2*m-1)>=n){printf("Error!\n");return 0;}
	for(int i=1;i<=n;i++)scanf("%d",&b),a[i]=b;
	for(int i=1;i<=n;i++)
	{
		int l=i+n-1;memset(f,0,2*n+1);
		for(int j=1;j<=n;j++)f[j][1]=f[j+n][1]=a[j];
		for(int j=i+1;j<=l;j++)
		{
			f[j][1]+=f[j-1][0];
			f[j][0]=max(f[j-1][1],f[j-1][0]);
		}
		r=min(r,max(f[l][1],f[l][0]));
	}
	printf("%d\n",r);
	return 0;
}
