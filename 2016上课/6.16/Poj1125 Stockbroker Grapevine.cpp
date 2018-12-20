#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[120][120],n,m,minx,maxx,log,a,b;

int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=99999999;
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			for(int j=1;j<=m;j++){
				scanf("%d%d",&a,&b);
				f[i][a]=b; f[i][i]=0;//自己到自己的距离为0 
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		minx=99999999;
		for(int i=1;i<=n;i++){
			maxx=-1;
			for(int j=1;j<=n;j++)
				maxx=max(maxx,f[i][j]);
			if(maxx<minx)
				minx=maxx,log=i;
		}
			
		printf("%d %d\n",log,minx);
	}
			
	return 0;
}
