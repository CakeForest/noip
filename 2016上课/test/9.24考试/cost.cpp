#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=200200;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int que[MAX],exist[MAX],top,rear;
void addarc(int x,int y,int c){
	go[++arcnum]=x;
	nxt[arcnum]=first[y];
	first[y]=arcnum;
	flow[arcnum]=c;
	
	go[++arcnum]=y;
	nxt[arcnum]=first[x];
	first[x]=arcnum;
	flow[arcnum]=c;
}

bool bfs(int start,int end,int cost){
	memset(exist,0,sizeof(exist));
	top=rear=0;
	que[rear++]=start;
	do{
		int u=que[top++];
		if(u==end) return true;
		for(int p=first[u];p;p=nxt[p]){
			if(!exist[go[p]]&&flow[p]<=cost){
				que[rear++]=go[p];
				exist[go[p]]=1;
			}
		}
	}while(top!=rear);
	return false;
}

int Find(int start,int end,int maxw){
	int s=1,e=maxw;
	while(s<=e){
		int m=(s+e)>>1;
		if(bfs(start,end,m)) e=m-1;
		else s=m+1;
	}
	return s;
}

int main()
{
	freopen("cost.in","r",stdin);
	freopen("cost.out","r",stdin);
	int n,m,a,b,w,maxw=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&w);
		addarc(a,b,w);
		maxw=max(maxw,w);
	}
	
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%d\n",Find(s,t,maxw));
	}
	
	return 0;
}
