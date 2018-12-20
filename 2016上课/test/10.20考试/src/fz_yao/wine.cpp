#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
struct node{
	int x,y,val;
}v[1000];
struct lin{
	int next,head,data;
}edge[100];
struct fc{
	int first,data;
}poi[100];

int addcount=0;
/*void addarc(int x,int y,int z)
{
	edge[++addcount].head=y;
	edge[addcount].next=poi[x].first;
	poi[x].first=addcount;
	edge[addcount].val=z;
}*/
int cnt=0;
void ad(int x,int y,int z)
{
	v[++cnt].x=x;
	v[cnt].y=y;
	v[cnt].val=z;
}

int father[100];
int getfather(int t)
{
	if(father[t]==t) return t;
	father[t]=getfather(father[t]);
	return father[t];
}
int unionn(int x,int y)
{
	int a=getfather(father[x]);
	int b=getfather(father[y]);
	if(a!=b)
	{
		father[x]=a;
		father[b]=a;
	}
}
int find_u(int x,int y)
{
	int a=getfather(father[x]);
	int b=getfather(father[y]);
	if(a!=b) return 1;
	else return 0;
}
int data[100],n,m,ans=0,tot;
int dis[100][100],md[100],a[100];
bool vis[100][100];
bool cmp(node x,node y)
{
	return x.val<y.val;
}

int main()
{
	int i,j;
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) {
		father[i]=i;	
		poi[i].first=-1;
	}
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	
	for(i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=z;
		dis[y][x]=z;
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			for(int k=0;k<n;k++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	} 
	
	for(i=0;i<n;i++)
	{
		if(a[i]!=0){
			tot++;
			for(j=0;j<n;j++)
			{
				if(j==i) continue;
				if(a[j]!=0&&vis[i][j]==0&&vis[j][i]==0)
				{
					ad(i,j,dis[i][j]);
					vis[i][j]=1;
					vis[j][i]=1;
				}
				
			}
		}
	}
	
	sort(v+1,v+1+cnt,cmp);
	

	for(i=1;i<=tot-1;i++)
	{
		int from=v[i].x,to=v[i].y,val=v[i].val;
		if(find_u(from,to)==1){
			unionn(from,to);
			ans+=val;
		}
	}
	printf("%d",ans);
	
	
	
	return 0;
}
