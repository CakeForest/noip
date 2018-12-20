#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,MAXM=10000;
int first[MAXN],nxt[MAXN],go[MAXN],arcnum=1,n;
int vis[MAXN],match[MAXN];
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
	for(int i=0;i<=n-1;i++)
		if(!vis[i]){
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ans++;
		}
	return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,c;
	while(scanf("%d",&n)!=EOF){
		memset(first,0,sizeof(first));
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			getchar();getchar();getchar();
			scanf("%d",&c);getchar();
			while(c--){
				scanf("%d",&b);
				addarc(a,b);
				addarc(b,a);
			}
		}
		printf("%d\n",n-MaxFlow());
	}
	return 0;
}
