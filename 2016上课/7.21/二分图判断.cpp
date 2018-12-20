#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int first[MAX],nxt[MAX],go[MAX],arcnum=1;
int que[MAX],top,rear,color[MAX];
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int BFS(int s){
	memset(color,-1,sizeof(color));
	top=rear=0;
	que[rear++]=s;
	color[s]=0;
	do{
		int u=que[top++],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(color[v]!=-1){
				if(color[u]==color[v]) return 1;
			}else{
				color[v]=color[u]^1;
				que[rear++]=v;
			}
		}
	}while(top!=rear);
	return 0;
}
int main()
{
	freopen("in.txt","r",stdin);
	int n,m,a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(first,0,sizeof(first));
		for(int i=1;i<=m;i++)
			scanf("%d%d",&a,&b),addarc(a,b);
		if(BFS(0)) printf("NOT BICOLORABLE.\n");
		else printf("BICOLORABLE.\n");
	}
	return 0;
}
