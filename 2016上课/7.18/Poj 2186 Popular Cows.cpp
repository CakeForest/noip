#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000+200,MAXM=50000+200;
int first[MAXN],nxt[MAXM],go[MAXM],arcnum=1;
int dfn[MAXN],low[MAXN],stack[MAXM],top;
int scc[MAXN],idx,cscc,vis[MAXN];//记录强连通分量 
int cd[MAXN],cd_scc[MAXN];
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
	cd[a]++;
}

void tarjan(int u){
	low[u]=dfn[u]=++idx;
	stack[++top]=u; vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p];
		if(vis[v]==0){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]==1)
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int v;
		cscc++;
		do{
			v=stack[top--];
			vis[v]=2;
			scc[v]=cscc; 
		}while(u!=v);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		addarc(a,b);
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
			tarjan(i);
			
	if(idx<n){
		printf("0");
		return 0;
	}
	for(int u=1;u<=n;u++)
		for(int p=first[u];p!=0;p=nxt[p]){
			int v=go[p];
			if(scc[u]!=scc[v])
				cd_scc[scc[u]]++;
		}
	int c1=0;
	for(int i=1;i<=cscc;i++){
		if(cd_scc[i]==0&&c1==0)
			c1=i;
		else if(c1!=0&&cd_scc[i]==0){
			printf("0");
			return 0;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
		if(scc[i]==c1)
			ans++;
	printf("%d",ans);
	
	return 0;
}
