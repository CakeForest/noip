#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int first[120],go[10000],nxt[10000],arcnum=1;
int dfn[120],low[120],idx;
int top,ans[120];
void addarc(int a,int b){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
}

void tarjan(int u){
	low[u]=dfn[u]=++idx;
//	stack[++top]=u;
	int son=0;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p];
		if(dfn[v]==0){
			tarjan(v); son++;
			low[u]=min(low[u],low[v]);
			if((u==1&&son>1)||(u!=1&&low[v]>=dfn[u])) ans[u]++;//一定使用这种方法记录u是否为割点 
		//		printf("u=%d son=%d ans=%d low[v]=%d dfn[u]=%d\n",u,son,ans,low[v],dfn[u]);
		}else low[u]=min(low[u],dfn[v]);
	}
	
	
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,a,b;
	char c;
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(first,0,sizeof(first));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(ans,0,sizeof(ans));
		arcnum=1; top=0;
		while(scanf("%d",&a)&&a!=0){
			do{
				scanf("%d",&b);
				if(a==b) continue;//一定不考虑自环 
				addarc(a,b);
				addarc(b,a);
				c=getchar();
			}while(c!='\n');
		}
		tarjan(1);
		int sum=0;
		for(int i=1;i<=n;i++)
			if(ans[i]) sum++;
		printf("%d\n",sum);
	}
	
	
	
	return 0;
}
