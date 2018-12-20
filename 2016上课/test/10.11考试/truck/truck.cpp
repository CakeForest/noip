#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
struct node{
	int x,y,val;
}v[50001];
struct lin{
	int next,head,val;
}edge[50001];
struct rt{
	int first,data;
}per[10001];
int father[50001],tot=0,n,m;
int deep[10001],anc[10001][30],fa[10001],dis[10001];
int g[10001][30],max_dp=0;
bool visited[10001];
void swap1(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int addcount=0;
void addarc(int x,int y,int z)
{
	edge[++addcount].head=y;
	edge[addcount].next=per[x].first;
	edge[addcount].val=z;
	per[x].first=addcount;
}

int getfather(int t)
{
	if(father[t]==t) return t;
	father[t]=getfather(father[t]);
	return father[t];
}

int find_u(int x,int y)
{
	int a,b;
	a=getfather(father[x]);
	b=getfather(father[y]);
	if(a!=b) return 1;
	else return 0;
}
int unionn(int x,int y)
{
	father[x]=getfather(father[x]);
	father[getfather(father[y])]=getfather(father[x]);
}

bool cmp(node x,node y)
{
	return x.val>y.val;
}

void dfs(int now)
{
	//anc[now][0]=fa[now];
	visited[now]=1;
	int i,j;
	for(i=per[now].first;i!=0;i=edge[i].next)
	{
		int hd=edge[i].head;
		if(visited[hd]==0){
			deep[hd]=deep[now]+1;
			max_dp=max(max_dp,deep[hd]);
			g[hd][0]=edge[i].val;
			anc[hd][0]=now;
			//dis[hd]=dis[now]+edge[i].val;
			dfs(hd);
		}
	}
}

void init(int len)
{
	int i,j;

//	int k=(int)(log((double)len)/log(2.0));
	for(j=1;j<=len;j++)
	{
		for(i=1;i<=n;i++)
		{
			anc[i][j]=anc[anc[i][j-1]][j-1];
			g[i][j]=min(g[i][j-1],g[anc[i][j-1]][j-1]);
		}
	}
}

int lca(int x,int y,int len)
{
	int i,j;
	int ans=INF;
//	int k=(int)(log((double)len)/log(2.0));
	if(deep[x]<deep[y]) swap1(&x,&y);

	for(j=len;j>=0;j--)
	{
		if(deep[anc[x][j]]>=deep[y]) 
		{
			ans=min(ans,g[x][j]);
			x=anc[x][j];
		}
	}
	if(x==y) return ans;
	for(j=len;j>=0;j--)
	{
		if(anc[x][j]!=anc[y][j])
		{
			ans=min(ans,g[x][j]);
			ans=min(ans,g[y][j]);
			x=anc[x][j];
			y=anc[y][j];
			
		}
	}
	ans=min(ans,g[x][0]);
	ans=min(ans,g[y][0]);
	return ans;
}



int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) father[i]=i;
	for(i=1;i<=m;i++)
	scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].val);
	sort(v+1,v+1+m,cmp);
	int q;
	scanf("%d",&q);
	node poi[30001];
	memset(g,0x3f,sizeof(g));
	memset(deep,0,sizeof(deep));
	for(i=1;i<=m;i++)
	{
		if(tot==n-1) break;
		int from,to,data;
		from=v[i].x,to=v[i].y,data=v[i].val;
		if(find_u(from,to)==1)
		{
			/*for(j=1;j<=q;j++)
			{
				if((getfather(poi[j].x)==getfather(from)&&getfather(poi[j].y)==getfather(to))||(getfather(poi[j].x)==getfather(to)&&getfather(poi[j].y)==getfather(from)))
				{
					poi[j].val=data;
				}
			}*/
			unionn(from,to);
			addarc(from,to,data);
			addarc(to,from,data);
			tot++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0) {deep[i]=1;
		 dfs(i);
		}
	}
	
	init(max_dp);
	
	
	
	for(i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y,max_dp));
	}
	/*for(i=1;i<=q;i++) {
		scanf("%d%d",&poi[i].x,&poi[i].y);	
		poi[i].val=-1;
	}*/
	
	
	/*for(j=1;j<=q;j++)
	printf("%d\n",poi[j].val);*/
	
	return 0;
}
