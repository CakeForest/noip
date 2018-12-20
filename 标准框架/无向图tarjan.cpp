#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int low[MAX],dfn[MAX],dex;
bool gd[MAX];//记录割点 
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

void tarjan(int u,int fa){
	low[u]=dfn[u]=++dex;
	int son=0;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		if(!dfn[v]){
			tarjan(v,u); son++;//子节点 
			low[u]=min(low[u],low[v]);
			if(u==1&&son>1||low[v]>=dfn[u]) gd[u]++;
	/*u为根节点时，如果有两个子节点则为割点
	 否则非根节点，low[v]大于等于dfn[u]即可 
	 */
		}else if(v!=fa) low[u]=min(low[u],dfn[v]);//不能用v来更新v的父亲 
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b);
		addarc(b,a);
	}
	tarjan(1);
	
}
