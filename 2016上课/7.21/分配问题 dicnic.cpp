#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
const int INF=99999999;
int n,k,m,a,b;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum=1;
int dis[MAX],que[MAX],top,rear;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int DFS(int u,int t,int minc){
	if(u==t) return minc;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p],f;
		if(dis[v]==dis[u]+1&&flow[p]>0){
			if(f=DFS(v,t,min(minc,flow[p]))){
				flow[p]-=f;
				flow[p^1]+=f;
				return f;
			}
		}
	}
	return 0;
}

int BFS(int s,int t){
	for(int i=0;i<=n+k+1;i++)
		dis[i]=INF;
	top=rear=0;
	que[rear++]=s;
	dis[s]=0;
	do{
		int u=que[top++],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(dis[v]==INF&&flow[p]>0){
				dis[v]=dis[u]+1;
				que[rear++]=v;
			}
		}
	}while(top!=rear);
	return dis[t]<INF;
}

int MaxFlow(int s,int t){
	int ans=0,f;
	if(BFS(s,t))
		while(f=DFS(s,t,INF))
			ans+=f;
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		addarc(a,n+b,1);
		addarc(n+b,a,0);
	}
	for(int i=1;i<=n;i++)
		addarc(0,i,1),addarc(i,0,0);
	for(int i=1;i<=k;i++)
		addarc(n+i,n+k+1,1),addarc(n+k+1,n+i,0);
	printf("%d",MaxFlow(0,n+k+1));
	
	return 0;
}
