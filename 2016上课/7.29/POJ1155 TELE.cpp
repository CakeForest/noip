#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3020;
const int MAXM=8000;
int first[MAXN],nxt[MAXM],go[MAXM],w[MAXM],arcnum;
int dp[MAXN][MAXN],sum[MAXN],temp[MAXN];
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	w[arcnum]=c;
}

void DFS(int u){
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p];
		DFS(v);
		for(int j=0;j<=sum[u];j++)
			temp[j]=dp[u][j];
		for(int j=0;j<=sum[u];j++)
			for(int k=1;k<=sum[v];k++)
				dp[u][k+j]=max(dp[u][k+j],temp[j]+dp[v][k]-w[p]);
		sum[u]+=sum[v];
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,m,b,c,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){//不能用memset,会使一个数负得太多从而变成正值 
          for(int j=1;j<=m;j++)  
              dp[i][j]=-10000000;  
    }  
	for(int i=1;i<=n-m;i++){
		scanf("%d",&t);
		sum[i]=0;
		while(t--){
			scanf("%d%d",&b,&c);
			addarc(i,b,c);
		}
	}
	for(int i=n-m+1;i<=n;i++){
		sum[i]=1;
		scanf("%d",&dp[i][1]);
	}
	DFS(1);
	for(int i=m;i>=0;i--)
		if(dp[1][i]>=0){
			printf("%d",i);
			break;
		}
	
	return 0;
}
