#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=50000;
int first[MAX],nxt[MAX],go[MAX],arcnum=1;
int match[MAX],vis[MAX];
int k,p,a,b,n;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int DFS(int u){
	vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p];
		int w=match[v];
		if(w<0||!vis[w]&&DFS(w)){
			match[v]=u;
			match[u]=v;
			return 1;
		}	
	}
	return 0;
}

int MaxFlow(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=n;i++){
		if(match[i]<0){
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ans++;
		}	
	}
	return ans;
}

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&k);
	while(k--){
		memset(first,0,sizeof(first));
		arcnum=1;
		scanf("%d%d",&p,&n);
		for(int i=1;i<=p;i++){
			scanf("%d",&a);
			while(a--){
				scanf("%d",&b);
				addarc(i+n,b);
				addarc(b,i+n);
			}
		}
		if(MaxFlow()==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
