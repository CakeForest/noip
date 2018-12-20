#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100000;
bool vis[MAX],contain[MAX];
int match[MAX],n,m,k;
int first[MAX],nxt[MAX],go[MAX],arcnum;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

bool dfs(int u){
	vis[u]=true;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		int w=match[v];
		if(!w||!vis[w]&&dfs(w)){
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;
}

int solve(){
	int ans=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		if(!match[i]){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
	}
	return ans;
}

int main(){
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int c,a,b;
		scanf("%d%d%d",&c,&a,&b);
		if(!a||!b) continue;
		addarc(a,b+n+1);
	}
	printf("%d",solve());
	
	return 0;
}
