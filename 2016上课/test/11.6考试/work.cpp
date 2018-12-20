#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=40000;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
bool vis[MAX];
int dist[MAX],tim[MAX];
queue <int> que;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addarc(b,a,c);
//		addarc(a,b,-c);
	}
	
	for(int i=1;i<=n;i++){
		memset(dist,127,sizeof(dist));
		memset(vis,0,sizeof(vis));
		memset(tim,0,sizeof(tim));
		dist[i]=0; vis[i]=true;
		que.push(i);
		do{
			int u=que.front(); vis[u]=false;
			for(int p=first[u];p;p=nxt[p]){
				int v=go[p],cha=flow[p];
				if(dist[u]+cha<dist[v]){
					dist[v]=dist[u]+cha;
					if(!vis[v]){
						que.push(v);
						vis[v]=true;
						tim[v]++;
						if(tim[v]>n){
							printf("NO SOLUTION\n");
							return 0;
						}
					}
				}
			}
			que.pop();
		}while(!que.empty());
		int flag=1;
		for(int i=1;i<=n;i++)
			if(dist[i]<0){flag=0;break;}
		if(flag){
			for(int i=1;i<=n;i++) printf("%d\n",dist[i]);
			break;
		}else continue;
	}
	
	
	
	
	return 0;
}
