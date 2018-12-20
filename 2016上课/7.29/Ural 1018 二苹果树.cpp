#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000;
int first[MAX],nxt[MAX],go[MAX],w[MAX][MAX],arcnum;
int f[MAX][MAX],father[MAX],lch[MAX],rch[MAX],vis[MAX];
int que[MAX],top,rear;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	w[a][b]=c;
}
int main(){
//	freopen("in.txt","r",stdin);
	int n,q,a,b,c;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
		addarc(b,a,c);
	}
	que[rear++]=1; vis[1]=1;
	do{
		int u=que[top++],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(vis[v]) continue;
			if(!lch[u]) lch[u]=v;
			else rch[u]=v;
			que[rear++]=v; vis[v]=1;
		}
	}while(top!=rear);
	
	for(int k=top-1;k>=0;k--){
		int i=que[k];
		if(!lch[i]) continue;
		for(int j=1;j<=q;j++){//分配j个树枝 
			f[i][j]=max(f[i][j],max(f[lch[i]][j-1]+w[i][lch[i]],f[rch[i]][j-1]+w[i][rch[i]]));//单独分配 
			for(int j0=1;j0<j;j0++){//两个都分配 
				int lw=f[lch[i]][j0-1]+w[i][lch[i]];
				int rw=f[rch[i]][j-j0-1]+w[i][rch[i]];
				f[i][j]=max(f[i][j],lw+rw);
			}
		}
	}
	printf("%d",f[1][q]);
	
	return 0;
}
