#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
//f[i]表示John走到i点时最小会抱怨的次数
const int MAX=100020;
struct node{
	int p,q;
}flow[MAX],fl[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
long long mina[MAX],minb[MAX];
int f[MAX];
int que[MAX],top,rear,vis[MAX];
int n,m;

int fir[MAX],nx[MAX],g[MAX],arc;
void addarc(int a,int b,int p,int q){
	nx[++arc]=fir[a];
	fir[a]=arc;
	g[arc]=b;
	fl[arc].p=p;
	fl[arc].q=q;
	
	nxt[++arcnum]=first[b];
	first[b]=arcnum;
	go[arcnum]=a;
	flow[arcnum].p=p;
	flow[arcnum].q=q;
}
int main(){
	freopen("gps.in","r",stdin);
	freopen("gps.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,p,q;
		scanf("%d%d%d%d",&a,&b,&p,&q);
		addarc(a,b,p,q);
	}
	
	for(int i=1;i<=n;i++) mina[i]=minb[i]=99999999;
	top=rear=0; mina[n]=0;
	que[rear++]=n;
	do{
		int u=que[top++];
		vis[u]=0;
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(mina[v]>mina[u]+flow[p].p){
				mina[v]=mina[u]+flow[p].p;
				if(!vis[v]){
					vis[v]=1;
					que[rear++]=v;
				}
			}
		}
	}while(top!=rear);
	
	memset(vis,0,sizeof(vis));
	top=rear=0; minb[n]=0;
	que[rear++]=n;
	do{
		int u=que[top++];
		vis[u]=0;
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(minb[v]>minb[u]+flow[p].q){
				minb[v]=minb[u]+flow[p].q;
				if(!vis[v]){
					vis[v]=1;
					que[rear++]=v;
				}
			}
		}
	}while(top!=rear);
	
	memset(f,127,sizeof(f));
	f[1]=0;
	rear=top=0;
	que[rear++]=1;
	do{
		int u=que[top++];
		for(int p=fir[u];p;p=nx[p]){
			int v=g[p];
			int val=f[u];
			if(abs(mina[u]-mina[v])!=fl[p].p) val++;
			if(abs(minb[u]-minb[v])!=fl[p].q) val++;
			if(val<f[v]){
				f[v]=val;
				que[rear++]=v;
			}
		}
	}while(top!=rear);
	printf("%d",f[n]);
	
	return 0;
}
