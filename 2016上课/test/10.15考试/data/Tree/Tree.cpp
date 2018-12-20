#include<cstdio>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<queue>  
#include<map>  
#include<set>  
#include<stack>  
#include<cstdlib>  
#include<string>  
#include<bitset>  
#define INF 1000000000  
#define fi first  
#define se second  
#define N 100005  
  
using namespace std;  
typedef long long LL;  
typedef pair<int,int> pii;  
int fa[N][20],dep[N],maxd,lg;  
int n,sz[N];  
vector<int> G[N];  
void initlca()  
{  
    int i,j;  
    lg=int(log(maxd)/log(2)+0.5);  
    for(j=1;j<=lg;j++)  
        for(i=1;i<=n;i++)  
            fa[i][j]=fa[fa[i][j-1]][j-1];  
}  
  
inline int lca(int u,int v)  
{  
    if(dep[u]>dep[v]) swap(u,v);  
    int i;  
    for(i=lg;i>=0;i--)  
        if(dep[fa[v][i]]>=dep[u])  
            v=fa[v][i];  
    if(u==v) return u;  
    for(i=lg;i>=0;i--)  
        if(fa[v][i]!=fa[u][i])  
            u=fa[u][i],v=fa[v][i];  
    return fa[v][0];  
}  
  
void dfs(int x)  
{  
    int i,len=G[x].size(),v;  
    maxd=max(maxd,dep[x]);  
    for(i=0;i<len;i++)  
    {  
        v=G[x][i];  
        if(v!=fa[x][0])  
        {  
            dep[v]=dep[x]+1;  
            fa[v][0]=x;  
            dfs(v);  
            sz[x]+=sz[v];  
        }  
    }  
    sz[x]++;  
}  
  
int get(int x,int b)  
{  
    for(int i=lg;i>=0;i--)  
        if(b&(1<<i))  
            x=fa[x][i];  
    return x;  
}  
  
int main()  
{  
    freopen("Tree10.in","r",stdin);
    freopen("Tree10.out","w",stdout);
	int a,b,m,c,d1,d2,d,y,i;  
    scanf("%d",&n);   
    for(i=1;i<n;i++)  
    {  
        scanf("%d%d",&a,&b);  
        G[a].push_back(b);  
        G[b].push_back(a);  
    }  
    fa[1][0]=1,dep[1]=1;  
    dfs(1);  
    initlca();  
  
    cin>>m;  
    while(m--)  
    {  
        scanf("%d%d",&a,&b);  
        c=lca(a,b);  
  
        d=dep[a]-dep[c]+dep[b]-dep[c];  
        if(d&1)  
            printf("0\n");  
        else if(a==b)  
            printf("%d\n",n);  
        else  
        {  
            d1=dep[a]-dep[c];  
            d2=dep[b]-dep[c];  
            d=d/2;  
            if(d1==d)  
            {  
                c=get(a,d-1);  
                y=get(b,d-1);  
                printf("%d\n",n-sz[c]-sz[y]);  
            }  
            else  
            {  
                if(d1>d2) c=get(a,d),y=get(a,d-1);  
                else c=get(b,d),y=get(b,d-1);  
  
                printf("%d\n",sz[c]-sz[y]);  
            }  
        }  
    }  
    return 0;  
}  
