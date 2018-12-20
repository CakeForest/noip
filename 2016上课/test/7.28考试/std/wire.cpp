#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=99999999;
int G[101][101],n,dis[101],point=1,ans=0;
bool vis[101];
int main()
{
	freopen("wire.in","r",stdin); 
	freopen("wire.out","w",stdout);
    memset(dis,127,sizeof(dis));
    memset(vis,false,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            G[i][j]=inf;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&G[i][j]);
    vis[1]=true;
    for(int i=1;i<n;i++)
    {
        dis[point]=0;
        for(int j=1;j<=n;j++) dis[j]=min(dis[j],G[j][point]);
        vis[point]=true;
        point=0;
        for(int j=1;j<=n;j++) point=!vis[j]&&(dis[j]<dis[point])?j:point;
        ans+=dis[point];
    }
    printf("%d",ans);
}
