#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX=1000000;
vector<int> ques[MAX];
int fa[MAX],first[MAX],nxt[MAX],go[MAX],arcnum;
int anscestor[MAX];
bool vis[MAX];
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int getfa(int p){
	if(p==fa[p]) return p;
	fa[p]=getfa(fa[p]);
	return fa[p];
}

void unions(int a,int b){
	a=getfa(a); b=getfa(b);
	if(a!=b) fa[a]=b;
}

void tarjan(int u){
	fa[u]=u;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		tarjan(v);
		unions(u,v);
		anscestor[getfa(u)]=u;//?????
	}
	vis[u]=true;
	for(int i=0;i<ques[u].size();i++){
		if(vis[ques[u][i]]){
			//找到匹配的答案，记录下来 
			
		}
	}
	
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b);
		ques[a].push_back(b);
		ques[b].push_back(a);
	}
	
	tarjan(1);
	
}
