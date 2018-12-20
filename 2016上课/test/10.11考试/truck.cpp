#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 99999999
using namespace std;
const int MAX=102000;
struct node{
	int a,b,len;
	bool friend operator < (const node &a,const node &b){
		return a.len>b.len;
	}
}road[MAX];
int n,m,q;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int fa[MAX],depth[MAX],f[MAX][32],d[MAX][32];
bool vis[MAX];
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int getfa(int p){
	if(p==fa[p]) return p;
	return fa[p]=getfa(fa[p]);
}

void unionn(int a,int b){
	a=getfa(a); b=getfa(b);
	fa[a]=b;
}

void buildz(){
	for(int j=1;j<=30;j++)
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
			d[i][j]=min(d[i][j-1],d[f[i][j-1]][j-1]);
		}
}

void dfs(int u){
	vis[u]=true;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		if(!vis[v]){
			depth[v]=depth[u]+1;
			f[v][0]=u;
			d[v][0]=flow[p];
			dfs(v);
		}
	}
}

int LCA(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int dc=depth[u]-depth[v];
	int minn=INF;
	for(int i=0;i<=30;i++)
		if((1<<i)&dc){
			minn=min(minn,d[u][i]);
			u=f[u][i];
		}
	if(u==v) return minn;
	
	for(int i=30;i>=0;i--)
		if(f[u][i]!=f[v][i]){
			minn=min(minn,min(d[u][i],d[v][i]));
			u=f[u][i]; v=f[v][i];
		}
	return min(minn,min(d[u][0],d[v][0]));
}

int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);

	memset(d,127,sizeof(d));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&road[i].a,&road[i].b,&road[i].len);
	}
	sort(road+1,road+1+m);
	int tot=0; for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		node &t=road[i];
		if(getfa(t.a)!=getfa(t.b)){
			addarc(t.a,t.b,t.len);
			addarc(t.b,t.a,t.len);
			unionn(t.a,t.b);
			tot++;
		}
		if(tot==n-1) break;
	}
	
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i);
	
	buildz();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(getfa(a)!=getfa(b)) printf("-1\n");
		else printf("%d\n",LCA(a,b));
	}
	
	
}
