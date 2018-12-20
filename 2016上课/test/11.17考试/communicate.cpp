#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=30000;
struct node{
	int x,y,t;
	bool friend operator <(const node &a,const node &b){
		return a.t<b.t;
	}
}l[MAX];
int n,m,q,fa[MAX];
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int depth[MAX],f[MAX][30],dist[MAX];
bool vis[MAX];
void read(int &num){
	char ch; num=0;
	while((ch=getchar())<'0'||ch>'9');
	num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
	return;
}

void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int getfa(int p){
	if(fa[p]==p) return p;
	else return fa[p]=getfa(fa[p]);
}

void unionn(int a,int b){
	a=getfa(a); b=getfa(b);
	fa[a]=b;
}

void dfs(int u){
	vis[u]=true;
	for(int p=first[u];p;p=nxt[p]){
		int &v=go[p];
		if(!vis[v]){
			vis[v]=true;
			depth[v]=depth[u]+1;
			dist[v]=dist[u]+flow[p];
			f[v][0]=u;
			dfs(v);
		}
	}
}

void buildz(){
	for(int j=1;j<=30;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}

int LCA(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int dc=depth[u]-depth[v];
	for(int i=0;i<=30;i++)
		if((1<<i)&dc) u=f[u][i];
	if(u==v) return u;
	
	for(int i=30;i>=0;i--){
		if(f[u][i]!=f[v][i])
			u=f[u][i];
			v=f[v][i];
	}
	return f[u][0];
}

int main(){
	freopen("communicate.in","r",stdin);
	freopen("communicate.out","w",stdout);
	
	read(n),read(m),read(q);
	for(int i=1;i<=m;i++){
		read(l[i].x),read(l[i].y),read(l[i].t);
		fa[i]=i;
	}
	
	sort(l+1,l+1+m);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int &a=l[i].x,&b=l[i].y;
		if(getfa(a)!=getfa(b)){
			unionn(a,b);
			addarc(a,b,l[i].t);
			addarc(b,a,l[i].t);
			cnt++;
			if(cnt==n-1) break;
		}
	}
	dfs(1);
	buildz();
	
	for(int i=1;i<=q;i++){
		int a,b;
		read(a),read(b);
		printf("%d\n",dist[a]+dist[b]-2*dist[LCA(a,b)]);
	}
	
	
	return 0;
}
