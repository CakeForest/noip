#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[60][60],sum[60][60];
int f[60][60][3600];
int main(){
	freopen("brike.in","r",stdin);
//	freopen("brike.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			sum[i][j]=sum[i-1][j]+a[i][j];
	
	for(int j=1;j<=n;j++) f[1][j][1]=a[1][j];
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int k=1;k<=m;k++){
				for(int v=0;v<=j-1;v++)
					f[i][j][k]=max(f[i][j][k],f[i-1][v][k-j]);
				f[i][j][k]+=sum[i][j];
			}
		}
	}
	
	printf("%d",f[n][1][m]);

	return 0;
}
