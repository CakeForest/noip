#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 99999999
using namespace std;
const int MAX=1e6;
int tick[MAX],nxt[MAX],tw[MAX],tk[MAX],arcnum;
int fa[MAX],f[2][MAX],ans[MAX];
//f[i][k] 表示走到i点时还剩k张票所花费的money 

int dp(int s){
	memset(f,127,sizeof(f));
	int maxx=0; bool now=0,pre=1;
	int minn=99999999;
	for(int p=tick[s];p;p=nxt[p]){
		f[0][tk[p]]=min(f[0][tk[p]],tw[p]);
		maxx=max(maxx,tk[p]);
		minn=min(minn,f[0][tk[p]]);
	}
	
/*	for(int i=0;i<=maxx;i++) printf("%lld ",f[now][i]);
		printf("\n");*/
	
	
	while(fa[s]){
		s=fa[s]; now^=1; pre^=1;
		for(int k=0;k<=maxx;k++)
			f[now][k]=INF;
		for(int p=tick[s];p;p=nxt[p]){//买票 
			f[now][tk[p]]=min(f[now][tk[p]],tw[p]+minn);
			maxx=max(maxx,tk[p]);
		}
		minn=INF;
		for(int k=0;k<=maxx;k++){//正常行走 
			f[now][k]=min(f[now][k],f[pre][k+1]);
			if(k) minn=min(minn,f[now][k]);
		}
		
/*		for(int i=0;i<=maxx;i++) printf("%lld ",f[now][i]);
		printf("\n");*/
		
	}
	int ans=INF;
	for(int k=0;k<=maxx;k++) ans=min(ans,f[now][k]);
	return ans;
}

void add(int v,int k,int w){
	nxt[++arcnum]=tick[v];
	tick[v]=arcnum;
	tw[arcnum]=w;
	tk[arcnum]=k;
}

int main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		fa[a]=b;
	}
	for(int i=1;i<=m;i++){
		int v,k,w;
		scanf("%d%d%d",&v,&k,&w);
		add(v,k,w);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int s; scanf("%d",&s);
		printf("%d\n",dp(s));
	}
	
	return 0;
}
