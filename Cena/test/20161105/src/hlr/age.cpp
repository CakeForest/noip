#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MAX=12000;
int cost[MAX]; bool vis[MAX];
int n,q,r;
int first[MAX],nxt[MAX],go[MAX],rd[MAX],arcnum;
int dfn[MAX],low[MAX],index;
int poi[MAX],cos[MAX],pnum;
queue<int> map;
stack<int> s;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

void tarjan(int u){
	dfn[u]=low[u]=++index;
	s.push(u);
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		if(!vis[v]){
			vis[v]=true;
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else low[u]=min(low[u],dfn[v]);
	}
	
	if(low[u]==dfn[u]){
		int v; pnum++;
		do{
			v=s.top();
			s.pop();
			poi[v]=pnum;
			if(cost[v]>0) cos[pnum]=min(cos[pnum],cost[v]);
		}while(u!=v);
	}
}

int main(){
	freopen("age.in","r",stdin);
	freopen("age.out","w",stdout);
	
	memset(cost,-1,sizeof(cost));
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		int id; scanf("%d",&id);
		scanf("%d",&cost[id]);
		map.push(id); vis[id]=true;
	}
	scanf("%d",&r);
	for(int i=1;i<=r;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b);
	}
	do{
		int u=map.front();
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(!vis[v]){
				vis[v]=1;
				map.push(v);
			}
		}
		map.pop();
	}while(!map.empty());
	
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			printf("NO\n%d",i);
			return 0;
		}
	memset(vis,0,sizeof(vis));
	memset(cos,127,sizeof(cos));

	for(int i=1;i<=n;i++)
		if(cost[i]>0&&!vis[i]) tarjan(i);
	for(int i=1;i<=n;i++)
		if(!poi[i]){
			poi[i]=++pnum;
			cos[pnum]=cost[i];
		}
	
	for(int u=1;u<=n;u++){
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(poi[u]!=poi[v]) rd[poi[v]]++;
		}
	}
	
	int ans=0;
	for(int i=1;i<=pnum;i++)
		if(!rd[i]) ans+=cos[i];
		
	printf("YES\n%d",ans);
	return 0;
}
