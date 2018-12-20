#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000;
const int MAXM=20000+200;
int n,k,r,c,match[MAXN],vis[MAXN];
int first[MAXN],go[MAXM],nxt[MAXM],arcnum=1;

void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int DFS(int u){
	vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p],w=match[v];
		if(w<0||!vis[w]&&DFS(w)){
			match[u]=v;
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int MaxFlow(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=n;i++)
		if(match[i]<0){
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ans++;
		}
	return ans;
}
int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=1;i<=k;i++){
			scanf("%d%d",&r,&c);
			addarc(r,c+n);
			addarc(c+n,r);
		}
		printf("%d\n",MaxFlow());
	}
	
	
	return 0;
}
