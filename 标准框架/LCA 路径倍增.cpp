#include<cstdio>
#include<algorithm>
#include<vector>
const int MAX=100000;
struct node{
	int go,flow;
	node(int a,int b):go(a),flow(b){}
};
int dist[MAX],depth[MAX],rt;
int fa[MAX][32];
bool vis[MAX],rd[MAX];
vector<node>tree[MAX];

void dfs(int u){//遍历整棵树 
	vis[u]=true;
	for(int i=0;i<tree[u].size();i++){
		int v=tree[u][i].go;
		if(!vis[u]){
			depth[v]=depth[u]+1;//深度 
			dis[v]=dis[u]+tree[u][i].flow;//距离 
			dfs(v);
		}
	}
}

void buildz(){
	for(int j=1;j<=30;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];s
}

int LCA(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int dc=depth[u]-depth[v];
	for(int i=0;i<=30;i++)//使两个结点的深度相同 
		if((1<<i)&dc) u=fa[u][i]; 
	if(u==v) return u;
	
	for(int i=30;i>=0;i--)
		if(fa[u][i]!=fa[v][i]){//一直倍增，直到倍增到LCA的子节点 
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];//返回LCA 向上跳一格 
}

int main(){
	int n,m,q,ance;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) tree.clear();//重置
	memset(dist,0,sizeof(dist)); 
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		tree[a].push_back(node(b,c));
		rd[b]=true;//入度不为0 
		fa[b][0]=a;//b的父亲是a 
	}
	
	for(int i=1;i<=n;i++) if(!rd[i]){rt=i;break;}//找根节点
	
	dfs(rt);//遍历整棵树 
	buildz();//树上倍增 
	
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ance=LCA(a,b);
		printf("%d\n",dis[a]+dis[b]-2*dis[ance]);
	}
	
}
