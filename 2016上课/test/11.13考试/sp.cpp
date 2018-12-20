#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 99999999
using namespace std;
const int MAX=300000;
queue <int> q;
int n,m,qq,a,b,c;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int col[MAX],fa[MAX],ans[1020][1020];
int dist[MAX]; bool exist[MAX];
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

void spfa(int s,int t){
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[s]=0; q.push(s);
	do{
		int u=q.front(); q.pop();
		exist[u]=0;
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p],w=flow[p];
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(!exist[v]){
					exist[v]=1;
					q.push(v);
				}
			}
		}
	}while(!q.empty());
}

int main(){
	freopen("sp.in","r",stdin);
	freopen("sp.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&qq);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
		addarc(b,a,c);
	}

	for(int i=1;i<=qq;i++){
		scanf("%d%d",&a,&b);
		if(!ans[a][b]){
			spfa(a,b);
			printf("%d\n",dist[b]);
			for(int i=1;i<=n;i++)
				if(dist[i]!=INF)
					ans[i][a]=ans[a][i]=dist[i];
		}else printf("%d\n",ans[a][b]);
	}
	
	return 0;
}
