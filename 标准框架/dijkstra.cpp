#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=100000;
struct node{
	int id; double val;
	node(int _id,double _val):id(_id),val(_val){}
	bool friend operator <(const node &a,const node &b){
		return a.val>b.val;
	}
};
double dist[MAX],flow[MAX];
int x[MAX],y[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
priority_queue <node> q;

double calc(int x1,int y1,int x2,int y2){
	return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}

void addarc(int a,int b,double c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b,calc(x[a],y[a],x[b],y[b]));
		addarc(b,a,calc(x[a],y[a],x[b],y[b]));
	}
	
	int s,t;
	scanf("%d%d",&s,&t);
	
	memset(dist,127,sizeof(dist));
	dist[s]=0; q.push(node(s,0));
	do{
		node no=q.top(); q.pop();
		int u=no.id;
		if(no.val!=dist[u]) continue;
	/*当该点到起点的距离不等于入队时的值，说明该点已经被更新，则直接跳过*/ 
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(dist[u]+flow[p]<dist[v]){
				dist[v]=dist[u]+flow[p];
				q.push(node(v,dist[v]));
			}
		}
	}while(!q.empty());
	
	printf("%.2f",dist[t]);
}
