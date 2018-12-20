#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;//求二分图最大流 
const int MAX=10000;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int match[MAX],vis[MAX];
int n,m,k,b;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int DFS(int u){
	vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p],w;
		w=match[v];
		if(w<0||!vis[w]&&DFS(w)){//寻找和v配对的结点！！！！！ 
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
	for(int i=1;i<=n;i++){//枚举每头牛 
		if(match[i]>0) continue;//如果已经配对，就不配对了 
		memset(vis,0,sizeof(vis));
		if(DFS(i)) ans++;
	}
	return ans;
}

int main(){
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&b);
			addarc(i,b+n);
			addarc(b+n,i);
		}
	}
	printf("%d",MaxFlow());
	
	
	return 0;
}
