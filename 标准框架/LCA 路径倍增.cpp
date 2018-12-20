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

void dfs(int u){//���������� 
	vis[u]=true;
	for(int i=0;i<tree[u].size();i++){
		int v=tree[u][i].go;
		if(!vis[u]){
			depth[v]=depth[u]+1;//��� 
			dis[v]=dis[u]+tree[u][i].flow;//���� 
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
	for(int i=0;i<=30;i++)//ʹ�������������ͬ 
		if((1<<i)&dc) u=fa[u][i]; 
	if(u==v) return u;
	
	for(int i=30;i>=0;i--)
		if(fa[u][i]!=fa[v][i]){//һֱ������ֱ��������LCA���ӽڵ� 
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];//����LCA ������һ�� 
}

int main(){
	int n,m,q,ance;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) tree.clear();//����
	memset(dist,0,sizeof(dist)); 
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		tree[a].push_back(node(b,c));
		rd[b]=true;//��Ȳ�Ϊ0 
		fa[b][0]=a;//b�ĸ�����a 
	}
	
	for(int i=1;i<=n;i++) if(!rd[i]){rt=i;break;}//�Ҹ��ڵ�
	
	dfs(rt);//���������� 
	buildz();//���ϱ��� 
	
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ance=LCA(a,b);
		printf("%d\n",dis[a]+dis[b]-2*dis[ance]);
	}
	
}
