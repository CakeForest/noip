#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1020;
int first[MAX],nxt[10200],go[10200],arcnum;
int dis[MAX][MAX],rd[MAX],val[MAX],stack[10200],top;
void addarc(int a,int b,int c){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
	dis[a][b]=c;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,x,y,z,maxx;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dis,0,sizeof(dis));
		memset(rd,0,sizeof(rd));
		memset(val,0,sizeof(val));
		memset(first,0,sizeof(first));
		maxx=-1; arcnum=1;
		for(int i=1;i<=n;i++)
			val[i]=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			addarc(++x,++y,z);
			rd[y]++;
		}
		for(int i=1;i<=n;i++)	
			if(rd[i]==0)
				stack[++top]=i;
		do{
			int u=stack[top--],v;
			for(int p=first[u];p!=0;p=nxt[p]){
				v=go[p];
				val[v]=max(val[v],val[u]+dis[u][v]);
				maxx=max(val[v],maxx);
				if(--rd[v]==0)
					stack[++top]=v;
			}
			
		}while(top!=0);
		printf("%d\n",maxx);
	}
	return 0;
}
