#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 5005
using namespace std;
int n,m;
int f[MAXN][MAXN],a[MAXN];
int main(){
	int k;
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m<<1>n){
		printf("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,143,sizeof(f));
	f[1][1]=a[1];f[2][1]=max(a[1],a[2]);
	for(int i=1;i<=n;i++){
		k=i>>1;
		for(int j=1;j<=k;j++)
			f[i][j]=max(f[i-2][j-1]+a[i],f[i-1][j]);
	}
	printf("%d",f[n][m]);
		
	return 0;
}
