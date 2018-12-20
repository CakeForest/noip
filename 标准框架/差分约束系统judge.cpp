#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=1000000;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int times[MAX],dist[MAX];
bool vis[MAX];
queue <int> q;
int n,m;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=b;
}

bool solve(int a,int b,int &ans){
	memset(dist,127,sizeof(dist));
	memset(vis,0,sizeof(vis));
	q.push(a); vis[a]=true;
	do{
		int u=q.front(); q.pop();
		vis[u]=false;
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(dist[u]+flow[p]<dist[v]){
				dist[v]=dist[u]+flow[p];
				if(!vis[v]){
					vis[v]=true;
					times[v]++;
					if(times[v]>n) return false;
					q.push(v);
				}
			}
		}
	}while(!q.empty());
	ans=dist[b];
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);//b-a<=c
	}
	
	int q1,q2;
	while(scanf("%d%d",&q1,&q2)){
		int t;
		if(solve(q1,q2,t)) printf("%d\n",t);
		else printf("NO SOLUTION\n");
	}
	
	
}
