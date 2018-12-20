#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10020;
const int MAXM=100020;
int first[MAXN],nxt[MAXM],go[MAXM],arcnum=1;
int dfn[MAXN],low[MAXN],stack[MAXM],top,dex,vis[10020];
int rt,ans[MAXN],temp[MAXN],sum;
void addarc(int a,int b){
    nxt[arcnum]=first[a];
    first[a]=arcnum;
    go[arcnum++]=b;
}
void tarjan(int u){
    dfn[u]=low[u]=++dex;
    stack[++top]=u; vis[u]=1;
    for(int p=first[u];p!=0;p=nxt[p]){
        int v=go[p];
        if(vis[v]==0){
            vis[v]=1;
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==1)
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int v; sum=0;
        do{
            v=stack[top--];
            vis[v]=2;
            temp[++sum]=v;
        }while(u!=v);
        if(rt<sum){//如果有更大的强连通分量 
        	rt=sum;
        	sort(temp+1,temp+1+sum);
        	for(int i=1;i<=sum;i++)
        		ans[i]=temp[i];
        }
        if(rt==sum){//如果有字典序更小的强连通分量 
        	sort(temp+1,temp+1+sum);
        	for(int i=1;i<=sum;i++)
        		if(temp[i]<ans[i]){
        			for(int i=1;i<=sum;i++)
        				ans[i]=temp[i];
        			break;
        		}
        }
    }
}
 
int main()
{
	freopen("tarjan.in","r",stdin);
	freopen("tarjan.out","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        addarc(a,b);
    }
     
    
    for(int i=0;i<=n-1;i++)
    	if(vis[i]==0){
    		top=0;dex=0;
    		memset(dfn,0,sizeof(dfn));
    		memset(low,0,sizeof(low));
    		stack[++top]=i;
    		tarjan(i);
    	}
    		
    for(int i=1;i<=rt;i++)
 	    printf("%d ",ans[i]);
     
    return 0;
}

