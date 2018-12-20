#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 55
using namespace std;
int a[N][N];
int sum[N][N]; 
int f[N][N][N*10];
int n,m;
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout); 
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++)
        for(int i=j;i<=n;i++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            sum[i][j]=sum[i][j-1]+a[i][j];
    int ans=-1;
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++)f[i][0][0]=0,f[i][1][1]=a[i][1];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;k<=m;k++){
                if(j<=k)
                    for(int p=j-1>=0?j-1:0;p<=i-1;p++)
                        if(f[i-1][p][k-j]!=-1)
                            f[i][j][k]=max(f[i][j][k],f[i-1][p][k-j]+sum[i][j]);
                if(k==m)ans=max(ans,f[i][j][k]);
            }
    printf("%d\n",ans);
}
