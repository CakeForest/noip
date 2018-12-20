#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 10005
using namespace std;
vector<int> tree[MAXN],que[MAXN];
int n,cnt,qa,qb,father[MAXN],anscestor[MAXN];
bool visited[MAXN],root[MAXN];
int getfa(int x){//取父亲 
	if(father[x]==x) return x;
	father[x]=getfa(father[x]);
	return father[x];
}

void unionn(int a,int b){//合并 
	a=getfa(a);
	b=getfa(b);
	if(a!=b)father[b]=a;
}
      
void tarjan(int u){
	father[u]=u;//当前祖先为u自身 
	int size=tree[u].size();
	for(int i=0;i<size;i++){//遍历所有相连的点 
		int v=tree[u][i];
		tarjan(v);//先继续向下遍历 
		unionn(u,v);//再将两个点合并起来 
		anscestor[getfa(u)]=u;//
	}
	visited[u]=true;//已经遍历 
	for(int i=0;i<que[u].size();i++){//所有跟u结点询问有关的点进行更新 
		if(visited[que[u][i]]){
			printf("%d\n",anscestor[getfa(que[u][i])]);
			break;
		}
	}
}
void init(){
	memset(visited,false,sizeof(visited));
	memset(root,false,sizeof(root));
	for(int i=1;i<=n;i++){
		father[i]=i;
		tree[i].clear();
		que[i].clear();
	}
}
int main(){
	int tcase,i,a,b;
	freopen("poj1330.txt","r",stdin);
	scanf("%d",&tcase);
	while(tcase--){
		init();
		scanf("%d",&n);
		for(i=1;i<=n-1;i++){
			scanf("%d%d",&a,&b);
			root[b]=true;
			tree[a].push_back(b);
		}
		scanf("%d%d",&qa,&qb);
		que[qa].push_back(qb);
		que[qb].push_back(qa);
		for(i=1;i<=n;i++)
			if(!root[i]){
				tarjan(i);
				break;
			}
	}
	return 0;
}
