#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=40000;
int map[200][200],dist[200];
int val[200],n;
int first[MAX],nxt[MAX],go[MAX],arcnum;
bool vis[MAX];
queue <int> que;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

long long bfs(int k){
	vis[k]=true; dist[k]=0;
	que.push(k);
	do{
		int u=que.front();
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(!vis[v]){
				dist[v]=dist[u]+1;
				que.push(v);
				vis[v]=true;
			}
		}
		que.pop();
	}while(!que.empty());
	
	long long cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=dist[i]*val[i];
	return cnt;
}

int main(){
	freopen("hospital.in","r",stdin);
	freopen("hospital.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d%d",&val[i],&a,&b);
		if(a){
			addarc(i,a);
			addarc(a,i);
		}
		if(b){
			addarc(i,b);
			addarc(b,i);
		}
	}
	
	long long minn=99999999;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(dist,127,sizeof(dist));
		long long t=bfs(i);
		if(t<minn) minn=t;
	}
	
	printf("%lld",minn);
	
	
	return 0;
}
