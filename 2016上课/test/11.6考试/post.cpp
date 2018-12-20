#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=1000000;
int n,m;
int fir1[MAX],nxt1[MAX],go1[MAX],flow1[MAX],arcnum1;
int fir2[MAX],nxt2[MAX],go2[MAX],flow2[MAX],arcnum2;
int dist[MAX];
bool vis[MAX];
queue<int> q;

void addarc1(int a,int b,int c){
	nxt1[++arcnum1]=fir1[a];
	fir1[a]=arcnum1;
	go1[arcnum1]=b;
	flow1[arcnum1]=c;
}

void addarc2(int a,int b,int c){
	nxt2[++arcnum2]=fir2[a];
	fir2[a]=arcnum2;
	go2[arcnum2]=b;
	flow2[arcnum2]=c;
}

int main(){
	freopen("post.in","r",stdin);
	freopen("post.out","w",stdout);
	
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addarc1(a,b,c);
		addarc2(b,a,c);
	}
	
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	q.push(1); vis[1]=true;
	do{
		int u=q.front(); q.pop();
		vis[u]=false;
		for(int p=fir1[u];p;p=nxt1[p]){
			int v=go1[p],w=flow1[p];
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}while(!q.empty());
	for(int i=2;i<=n;i++) ans+=dist[i];
	
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	q.push(1); vis[1]=true;
	do{
		int u=q.front(); q.pop();
		vis[u]=false;
		for(int p=fir2[u];p;p=nxt2[p]){
			int v=go2[p],w=flow2[p];
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}while(!q.empty());
	for(int i=2;i<=n;i++) ans+=dist[i];
	
	printf("%lld",ans);
	
	return 0;
}
