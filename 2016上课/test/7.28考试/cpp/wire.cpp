#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=99999999;
int map[120][120],minn[120],vis[120];

int main(){
	freopen("wire.in","r",stdin);
	freopen("wire.out","w",stdout);
	int n,a,b,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&map[i][j]);
	vis[1]=1;
	for(int j=1;j<=n;j++)
		minn[j]=map[1][j];
	for(int k=1;k<=n-1;k++){
		int minx=INF,t;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&minn[i]<minx)
				minx=minn[i],t=i;
		vis[t]=1;
		ans+=minn[t];
		for(int j=1;j<=n;j++)
			if(!vis[j]&&minn[j]>map[t][j])
				minn[j]=map[t][j];		
	}
	printf("%d",ans);
	
	return 0;
}
