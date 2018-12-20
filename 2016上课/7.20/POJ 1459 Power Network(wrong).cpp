#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=99999999;
int first[10200],nxt[30600],go[30600],flow[10200],arcnum=1;
int que[30600],dis[30600],top,rear;
int s[10200],p[10200],c[10200];
int n,np,nc,m,u,v,z;
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
			f=DFS(v,t,min(minc,flow[p]));
			if(f){
				flow[p]-=f;
				flow[p^1]+=f;
				return f;
			}
		}
	}
	return 0;
}

int BFS(int s,int t){
	for(int i=0;i<=n+1;i++)
		dis[i]=INF;
	top=rear=0;
	que[rear++]=s;
	dis[s]=0;
	do{
		int u=que[top++],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(flow[p]>0&&dis[v]==INF){
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

int GetData(){
	char c; int data;
	do c=getchar();
	while(c==' '||c=='\n');
	scanf("%d\n",&data);
	return data;
}

int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
		memset(first,0,sizeof(first));
		memset(flow,0,sizeof(flow));
		arcnum=1;
		for(int i=1;i<=m;i++){
			u=GetData();v=GetData();z=GetData();
			addarc(u,v,z);//u到v的容量为z 
	//		addarc(v,u,0);//建立反向边 
		}
		for(int i=1;i<=np;i++){//发电站 
			u=GetData();z=GetData();
			addarc(n,u,z);//从超级源点到发电站 
		}
		for(int i=1;i<=nc;i++){//消费者 
			u=GetData();z=GetData();
			addarc(u,n+1,z);//从消费者到超级汇点 
		}
		printf("%d\n",MaxFlow(n,n+1));
		
	}
	return 0;
}
