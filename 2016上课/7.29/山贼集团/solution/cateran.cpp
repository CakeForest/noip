#include<stdio.h>
#include<string.h>
#include<time.h>

const int maxn = 200;
const int maxp = 12;
const int maxs = 1<<12;

int ans[maxn][maxs];
int g[maxn][maxn],cnt[maxn];
int a[maxn][maxp],A[maxn][maxs],cost[maxs],tmp[maxs],tmp2[maxs];
int table[maxs][maxs],end[maxs];
int n,p,x,y,t,s,u;

#define FORALL(op) { t=s=0; while(t<(1<<p)){ op; u=(t&s)+1; u=(u&-u); if(t&u){t-=u-1;s+=1;}else{t+=1;s-=u-1;} } }
#define FORALL2(op) { for(t=(1<<p)-1;t>=0;t--) for(u=0;u<end[t];u++) { s=table[t][u]; op; } }

void init(int x,int f=0)
{
	int p=-1;
	for(int i=0;i<cnt[x];i++)
		if(g[x][i]!=f)init(g[x][i],x);
		else p=i;
	if(p!=-1){g[x][cnt[x]-1]^=g[x][p]^=g[x][cnt[x]-1]^=g[x][p]; cnt[x]--;}
}

void getinfo()
{
	int v,c,x,y;
	scanf("%d%d",&n,&p);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y); x--; y--;
		g[x][cnt[x]++]=y; g[y][cnt[y]++]=x;
	}
	init(0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<p;j++) scanf("%d",&a[i][j]);
		for(int j=0;j<(1<<p);j++) for(int k=0;k<p;k++) if(j&(1<<k)) A[i][j]+=a[i][k];
	}
	for(scanf("%d",&t);t;t--)
	{
		for(scanf("%d%d",&v,&c),s=0;c;c--,s+=(1<<(x-1))) scanf("%d",&x);
		tmp[s]+=v;
	}
	FORALL(table[t][end[t]++]=s);
	FORALL2(cost[t]+=tmp[s]);
}

void dfs(int x)
{
	for(int i=0;i<cnt[x];i++) dfs(g[x][i]);
	memset(tmp,192,sizeof(tmp)); tmp[0]=0;
	for(int i=0;i<cnt[x];i++)
		FORALL2( if(tmp[t]<tmp[t-s]+ans[g[x][i]][s])tmp[t]=tmp[t-s]+ans[g[x][i]][s] );
	memset(ans[x],192,sizeof(ans[x]));
	FORALL2( if(ans[x][t]<tmp[s]-A[x][t-s]+cost[t])ans[x][t]=tmp[s]-A[x][t-s]+cost[t] );
}

int main()
{
	freopen("cateran.in","r",stdin); freopen("cateran.out","w",stdout);
	getinfo();
	dfs(0);
	printf("%d\n",ans[0][(1<<p)-1]);
	return 0;
}
