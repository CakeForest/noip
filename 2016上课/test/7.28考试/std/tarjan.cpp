#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int first[10020],nxt[100200],go[100200],arcnum=1;
int dfn[10020],low[10020],stack[100200],top,dex,vis[10020];
int rt,ans[10020],temp[10020],sum;
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
        if(rt<sum){
            rt=sum;
            for(int i=1;i<=sum;i++)
                ans[i]=temp[i];
        }
    }
}
  
int main()
{
    int n,m,a,b;
    freopen("tarjan.in","r",stdin);
	freopen("tarjan.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        addarc(a,b);
    }
      
     
    for(int i=1;i<=n;i++)
        if(vis[i]==0){
            top=0;dex=0;
            memset(dfn,0,sizeof(dfn));
            memset(low,0,sizeof(low));
            stack[++top]=i;
            tarjan(i);
        }
             
      
    sort(ans+1,ans+1+rt);
    for(int i=1;i<=rt;i++)
 //     if(ans[i]!=0)
        printf("%d ",ans[i]);
      
    return 0;
}
