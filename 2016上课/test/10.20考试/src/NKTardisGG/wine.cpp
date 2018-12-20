#include<cstdio>
#include<iostream>
#include<queue>
#define inf 1e7
using namespace std;
inline void _in(int &d)
{
	char t=getchar();bool f=false;
	while(!isdigit(t)){if(t==45)f=true;t=getchar();}
	for(d=0;isdigit(t);t=getchar())d=d*10+t-48;
	if(f)d=-d;
}
queue<int>q;
bool flag[20];
int n,m,c[20][20],dis[20],w[20][20],path[20],tot,MF,MC;
bool spfa()
{
     int i,j,now;
     for(i=1;i<=n;i++){dis[i]=inf;path[i]=-1;flag[i]=false;}
     dis[1]=path[1]=0;flag[1]=true;q.push(1);
     while(q.size())
     {
          i=q.front();q.pop();flag[i]=false;
          for(j=1;j<=n;j++)
		  if(c[i][j]>0&&dis[j]>dis[i]+w[i][j])
		  {
		  	dis[j]=dis[i]+w[i][j];
            path[j]=i;
            if(!flag[j])
            {
                flag[j]=true;
                q.push(j);
            }
		  }
	}
     if(dis[n]<inf)return true;
	 else return false; 
}
void addflow()
{
      int flow=inf,cost=0,i=n;
      while(i!=1&&path[i])
      {
          if(flow>c[path[i]][i])flow=c[path[i]][i];
          cost+=w[path[i]][i];
          i=path[i];
    }
      MF+=flow;
      i=n;
      while(i!=1)
      {
          c[path[i]][i]-=flow;
          c[i][path[i]]+=flow;
          i=path[i];
      }
 }
int i,j,a,b,end;
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	_in(n);_in(m);
	end=n+2;
	for(i=2;i<=n+1;i++)
	{
		_in(a);
		if(a>0)c[1][i]=a,tot+=a;
		else c[i][end]=-a;
	}
	n=n+2;
	for(i=1;i<=m;i++)
	{
		_in(a);_in(b);
		a+=2;b+=2;
		_in(w[a][b]);
		c[a][b]=inf;
	}
	while(spfa())addflow();
	if(MF==tot)
	{
		for(i=2;i<n;i++)
		for(j=2;j<n;j++)
		if(c[i][j]&&c[i][j]!=inf)MC+=w[i][j];
		cout<<MC;
	}
	else cout<<"Impossible";
}
