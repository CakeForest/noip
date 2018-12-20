#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF=99999999;
struct node{
	int id;
	double t;
	bool friend operator <(const node &a,const node &b){
		return a.t>b.t;
	}
	node(int a,double b):id(a),t(b) {}
};
const int MAX=200;
int ll[MAX][MAX],vv[MAX][MAX],f[MAX][MAX],limit[MAX],prev[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
bool vis[MAX]; double dist[MAX];
priority_queue <node> q;

void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}
int main(){
	freopen("speed.in","r",stdin);
//	freopen("speed.out","w",stdout);
	
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	d++;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a++; b++;
		scanf("%d%d",&vv[a][b],&ll[a][b]);
		addarc(a,b);
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[1]=0; limit[1]=70;
	q.push(node(1,0));
	do{
		node no=q.top(); q.pop();
		int u=no.id;
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			double temp;
			temp=1.0*ll[u][v]/limit[u];
			if(dist[u]+temp<dist[v]){
				limit[v]=!vv[u][v]?limit[u]:vv[u][v];
				dist[v]=dist[u]+temp;
				prev[v]=u;
				q.push(node(v,dist[v]));
			}
		}
	}while(!q.empty());
	
	printf("%llf",dist[d]);
	
	return 0;
}
