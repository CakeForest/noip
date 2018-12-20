#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int first[1200],go[10000],nxt[10000],arcnum=1;
int dfn[1200],low[1200],exist[1200],rt,idx,ans[1200];
int cut,vis[1200];
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
}
void tarjan(int u){
	low[u]=dfn[u]=++idx;
	int son=0,v;
	for(int p=first[u];p!=0;p=nxt[p]){
		v=go[p];
		if(dfn[v]==0){
			tarjan(v); son++;
			low[u]=min(low[u],low[v]);
			if((u==rt&&son>1)||(u!=rt&&low[v]>=dfn[u])) ans[u]=1;
		}else low[u]=min(low[u],dfn[v]);
	}
}
void dfs(int u){//DFS找相连子网络 
	if(vis[u]) return;
	vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p])
		if(go[p]!=cut)
			dfs(go[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,k=0,cnt;
	while(scanf("%d",&a)){
		if(a==0) break;
		k++;
		memset(first,0,sizeof(first));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(exist,0,sizeof(exist));
		memset(ans,0,sizeof(ans));
		arcnum=1; idx=0; cnt=0;
		do{
			scanf("%d",&b);
			exist[a]=exist[b]=1;
			if(a==b) continue;//忽略自环 
			addarc(a,b);
			addarc(b,a);
		}while(scanf("%d",&a)&&a!=0);
		rt=b;
		tarjan(rt);
		if(k>1) printf("\n");
		printf("Network #%d\n",k);
		for(cut=1;cut<=1000;cut++)
			if(exist[cut]&&ans[cut]){
				int sum=0;
				memset(vis,0,sizeof(vis));
				for(int i=1;i<=1000;i++)
					if(exist[i]&&!vis[i]&&!ans[i])//一定不能遍历割点本身 
						dfs(i),sum++;
				printf("  SPF node %d leaves %d subnets\n",cut,sum);
				cnt++;
			}
		if(cnt==0) printf("  No SPF nodes\n");
	}
	
	
	return 0;
}
