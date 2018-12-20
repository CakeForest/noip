#include <cstdio>

long long f[6000];

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			f[j]=(f[j]+f[j-i])%1000000000;
		}
	}
	printf("%lld",f[m]);
 } 
