#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t[200200],n,m;
int f[2050][2050][2];
//f[i][j][k]前i个数中选择了j个数，其中k为是否选择第i个点 
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int ans=-1;
	
	scanf("%d%d",&n,&m);
	if(n<m*2){printf("Error!");return 0;}
	
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	
	f[1][1][1]=0;
	for(int j=1;j<=m;j++){
		for(int i=2;i<=n;i++){
			f[i][j][1]=max(f[i-2][j-1][1]+t[i],f[i-1][j-1][0]+t[i]);
			f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
		}
	}
	ans=max(f[n][m][1],f[n][m][0]);
	
	memset(f,0,sizeof(f));
	f[1][1][1]=t[1];
	for(int j=1;j<=m;j++){
		for(int i=2;i<=n;i++){
			f[i][j][1]=max(f[i-2][j-1][1]+t[i],f[i-1][j-1][0]+t[i]);
			f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
		}
	}
	ans=max(ans,f[n][m][0]);
	printf("%d",ans);
	
	return 0;
}
