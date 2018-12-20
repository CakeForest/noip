#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000+20;
const int MAXM=10000+20;
int first[MAXN],go[MAXM],nxt[MAXM],arcnum=1;
int low[MAXN],dfn[MAXN],dex,cnt[MAXN],map[MAXN][MAXN],sum;
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
}

void tarjan(int u,int father){
	low[u]=dfn[u]=++dex;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p];
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}else if(v!=father) low[u]=min(low[u],dfn[v]);//不能用v来更新v的父亲 
	}
}

int main()
{
	int n,m,a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			if(map[min(a,b)][max(a,b)]) continue;
			map[min(a,b)][max(a,b)]=1;
			addarc(a,b);
			addarc(b,a);
		}
		tarjan(1,-1);
		for(int u=1;u<=n;u++)
			for(int p=first[u];p!=0;p=nxt[p]){
				int v=go[p];
				if(low[u]!=low[v])
					cnt[low[u]]++;
			}
		for(int i=1;i<=n;i++)
			if(cnt[i]==1)
				sum++;
		printf("%d",(sum+1)/2);
	}
	
	
	
	return 0;
}

