#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=99999999;
const int MAX=1500;
double data[MAX];
int first[MAX],go[MAX],nxt[MAX],arcnum=1,x[MAX],y[MAX],r[MAX];
int flow[MAX],que[MAX],top,rear,dis[MAX],vis[MAX];
int k,n,ans;
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
		if(dis[v]==dis[u]+1&&flow[p]>0)
			if(f=DFS(v,t,min(minc,flow[p]))){
				flow[p]-=f;
				flow[p^1]+=f;
				return f;
			}
	}
	return 0;
}

int BFS(int s,int t){
	for(int i=1;i<=n;i++)
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
	while(BFS(s,t))
		while(f=DFS(s,t,INF))
			ans+=f;
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&k);
	while(k--){
		memset(flow,0,sizeof(flow));
		memset(first,0,sizeof(first));
		arcnum=1;
		scanf("%d",&n);
		int red=0,purple=n+1;
		data[0]=9999; data[n+1]=0;
		for(int i=1;i<=n;i++){
			scanf("%f%d%d%d",&data[i],&x[i],&y[i],&r[i]);
			if(data[i]<data[red]) red=i;
			if(data[i]>data[purple]) purple=i;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(data[i]<data[j]&&sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<=r[i]+r[j])
					addarc(i,j,1),addarc(j,i,0);
		if(MaxFlow(red,purple)<2) printf("Game is NOT VALID\n");
		else printf("Game is VALID\n");	
	}
	
	
	return 0;
}
