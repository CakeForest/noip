#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b;
	int cost;
}t[20];
int n,m,fa[20],val[20],mincost;
int ttt[20];
int nowcost;

void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
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

void dfs(int depth,int id){
	
	
	int flag=0;
	memset(ttt,0,sizeof(ttt));
	init();
	for(int i=0;i<depth-1;i++){
		if((id>>i)&1)
			unions(t[i].a,t[i].b);
	}
	for(int i=1;i<=n;i++){
		int temp=val[i];
		ttt[fa[i]]+=temp;
	}
	for(int i=1;i<=n;i++) if(ttt[i]){
		flag=1;
		break;
	}
	if(!flag){
		mincost=min(mincost,nowcost);
	//	return;
	}
	
	if(depth>n) return;
	dfs(depth+1,id);
	
	nowcost+=t[depth].cost;
	id=id|(1<<(depth-1));
	dfs(depth+1,id);
	nowcost-=t[depth].cost;
}



int main(){
	freopen("wine.in","r",stdin);
//	freopen("wine.out","w",stdout);
	
	mincost=99999999;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].cost);
		t[i].a++; t[i].b++;
	}
	
	dfs(1,0);
	printf("%d",mincost);
	
	
	return 0;
}
