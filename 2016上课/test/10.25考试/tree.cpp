#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=210000;
//先序遍历，每个节点存该树的最后一个节点 
int n,m;
int fir[MAX],nx[MAX],g[MAX],cnum;
int first[MAX],nxt[MAX],go[MAX],tail[MAX],arcnum=1,pnum=1;
int to[MAX];
//int e[MAX];
bool ok[MAX]; bool vis[MAX];
/*
	思想：先建一个先序遍历树，tail存每个节点的子树中最后面的节点 
	那么线段树就可以很方便对树上的集合进行操作了 
*/

/*
int lowbit(int x){return -x&x;}
int update(int x,int p){
	while(x<=n){
		e[x]+=p;
		x+=lowbit(x);
	}
}
*/


int sum[MAX<<2],lazy[MAX<<2];//开4倍空间 
void PushUp(int rt){//向上更新 
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int c){//向下更新 
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];//注意是+
		sum[rt<<1]+=(c-(c>>1))*lazy[rt];
		sum[rt<<1|1]+=(c>>1)*lazy[rt];//注意更新这两个结点 
		lazy[rt]=0;//lazy置0 
	}
}
void update(int L,int R,int p,int l,int r,int rt){//更新 
	if(L<=l&&r<=R){
		lazy[rt]+=p;
		sum[rt]+=p*(r-l+1);//注意更新本结点
		return;//注意返回 
	}
	PushDown(rt,r-l+1);//注意向下更新 
	int m=(l+r)>>1;
	if(L<=m) update(L,R,p,lson);
	if(R>=m+1) update(L,R,p,rson);
	PushUp(rt);//注意向上更新 
}
int view(int L,int R,int l,int r,int rt){//求和 
	if(L<=l&&r<=R) return sum[rt];
	PushDown(rt,r-l+1);//注意向下更新 
	int m=(l+r)>>1;
	int tot=0;
	if(L<=m) tot+=view(L,R,lson);
	if(R>=m+1) tot+=view(L,R,rson);
	return tot;
}

void add(int a,int b){//第一遍生成树 
	nx[++cnum]=fir[a];
	fir[a]=cnum;
	g[cnum]=b;
}

void addarc(int a,int b){//先序遍历树 
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int last;//记录当前树的孩子中最右边的那一个 
void dfs(int u,int u1){
	to[u]=u1;
	vis[u]=1;
	for(int p=fir[u];p;p=nx[p]){
		if(vis[g[p]]) continue;
		int v=g[p],v1=++pnum;
		addarc(u1,v1);//新树加边
		last=v1;//当前最右边孩子为v 
		dfs(v,v1);
	}
	tail[u1]=last;
	update(u1,u1,1,1,n,1);
//	update(u1,1);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	dfs(1,1);
	for(int i=1;i<=pnum;i++) ok[i]=true;

	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		char c=' '; int a;
		while(c!='Q'&&c!='C') c=getchar();
		
		scanf("%d",&a); 
		if(c=='Q'){
			a=to[a];
			int ans=view(a,tail[a],1,n,1);
//			int ans=e[a]-e[tail[a]]+1;
			printf("%d\n",ans);
		}else{
			a=to[a];
			if(ok[a]) update(a,a,-1,1,n,1);
			else update(a,a,1,1,n,1);
	/*		if(ok[a]) update(a,-1);
			else update(a,1);*/
			ok[a]=!ok[a];
		}
	}
	
/*	printf("\n\n\n");
	for(int i=1;i<=pnum;i++){
		printf("%d\n",view(to[i],tail[to[i]],1,n,1));
	}printf("\npnum=%d",pnum);*/
	
	
/*	printf("nxt:\n");
	for(int i=1;i<=arcnum;i++) printf("%d ",nxt[i]);
	printf("\nfirst:\n");
	for(int i=1;i<=pnum;i++) printf("%d ",first[i]);
	printf("\ngo:\n");
	for(int i=1;i<=arcnum;i++) printf("%d ",go[i]);
	printf("\ntail:\n");
	for(int i=1;i<=pnum;i++) printf("%d ",tail[i]);*/
	
	return 0;
}
