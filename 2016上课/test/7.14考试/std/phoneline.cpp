#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct data{int to,next,v;}e[20001];
int n,p,k,cnt,head[1001],dis[1001],q[1001],inq[1001],ans=-1;
void insert(int u,int v,int w)
{cnt++;e[cnt].to=v;e[cnt].v=w;e[cnt].next=head[u];head[u]=cnt;}
bool spfa(int x)
{
     memset(dis,127/3,sizeof(dis));
     int t=0,w=1,i,now,s;
     dis[1]=0;q[t]=1;inq[1]=1;
     while(t!=w)
     {
        now=q[t];t++;if(t==1001)t=0;
        i=head[now];
        while(i)
        {
            if(e[i].v>x)s=dis[now]+1;
            else s=dis[now];
            if(s<dis[e[i].to])
            {
                dis[e[i].to]=s;
                if(!inq[e[i].to])
                {
                   q[w++]=e[i].to;
                   inq[e[i].to]=1;
                   if(w==1001)w=0;
                }
            }
            i=e[i].next;
        }
        inq[now]=0; 
    }
     if(dis[n]<=k)return 1;
     return 0;
 }
int main()
{
	freopen("phoneline.in","r",stdin);
	freopen("phoneline.out","w",stdout);
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=p;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        insert(u,v,w);insert(v,u,w);
    }
    int l=0,r=1000000;
    while(l<=r)
    {
       int mid=(l+r)>>1;
       if(spfa(mid)){ans=mid;r=mid-1;}
       else l=mid+1;
    } 
    printf("%d",ans);
    return 0;
}
