#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=600;
const int INF=99999999;
int first[MAX],go[MAX],nxt[MAX],flow[MAX],arcnum=1;
int que[MAX*MAX],dis[MAX],top,rear,current[MAX],vis[MAX];
int n,m,a,b,c;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int DFS(int u,int t,int minc){
//	printf("dfs %d %d start\n",u,t);
	if(u==t) return minc;
	for(int p=current[u];p!=0;p=nxt[p]){
		current[u]=p;
		int v=go[p];
//		printf("%d: %d->%d\n",p,u,v);
		if(dis[v]==dis[u]+1&&flow[p]>0){//边符合BFS顺序 且 边剩余容量大于零
			int f=DFS(v,t,min(minc,flow[p]));
			if(f){
				flow[p]-=f;
				flow[p^1]+=f;
				return f;
			}
		}
	}
	return 0;
}

int BFS(int s,int t){//BFS优化 
	for(int i=1;i<=MAX;i++)
		dis[i]=INF;
	top=rear=0;
	que[rear++]=s;
	dis[s]=1;
	do{
		int u=que[top++],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(flow[p]>0&&dis[v]==INF){//边剩余容量大于零且点未被更新时才更新 
				dis[v]=dis[u]+1;
				que[rear++]=v;
			}
		}
	}while(top!=rear);
	return dis[t]<INF;//返回是否找到增广路 
}

int MaxFlow(int s,int t){//Dinic算法 
	int ans=0,f;
	while(BFS(s,t)){
		for(int i=1;i<=n;i++)//每次DFS之前都要重置current数组 
			current[i]=first[i];
		while(f=DFS(s,t,INF)) ans+=f;
	}
	return ans;
}

int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(first,0,sizeof(first));
		memset(flow,0,sizeof(flow));
		arcnum=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			addarc(a,b,c);
			addarc(b,a,0);
		}
/*		for(int i=1;i<=n;i++){
			printf("%d %d\n",i,first[i]);
		}
		printf("node end\n");
		for(int i=1;i<=2*m;i++){
			printf("%d %d %d\n",i,go[i],nxt[i]);
		}
		printf("edge end\n");*/
		printf("%d\n",MaxFlow(1,n));
	}

	return 0;
}
