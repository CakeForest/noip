#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 500
#define inf 0x3fffffff
int fa[20],V[20],fv[20];
int x[MAXN],y[MAXN],z[MAXN],c[MAXN],n,m,ANS=inf;
int X[MAXN],Y[MAXN],Z[MAXN];
int Minn[MAXN];
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		fv[i]=V[i];
	}
	return ;
}
bool cmp(int a,int b)
{
	return z[a]<z[b];
}
int getfa(int x)
{
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
bool ok()
{
	for(int i=1;i<=n;i++)
	{
		if(fv[getfa(i)])
		{
			return false;
		}
	}
	return true;
}
int CC()
{
	int cc=0;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i&&fv[i])
		{
			cc++;
		}
	}
	return cc;
}
void dfs(int p,int cost)
{

	if(cost+Minn[(CC()+1)/2]>=ANS)
	{
		return ;
	}
	int tf[20],tv[20];
	for(int i=1;i<=n;i++)
	{
		tf[i]=fa[i];
		tv[i]=fv[i];
	}
	if(ok())
	{
		ANS=cost;
		return ;
	}
	if(p>m)
	{
		return ;
	}
	int fx=getfa(X[p]),fy=getfa(Y[p]);
	if(fx==fy)
	{
		dfs(p+1,cost);
		return ;
	}
	else 
	{
		fa[fx]=fy;
		fv[fy]+=fv[fx];
		dfs(p+1,cost+Z[p]);
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=tf[i];
		fv[i]=tv[i];
	}
	dfs(p+1,cost);
	return ;
}
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&V[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		x[i]++;
		y[i]++;
		c[i]=i;
	}
	sort(c+1,c+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		X[i]=x[c[i]];
		Y[i]=y[c[i]];
		Z[i]=z[c[i]];
	}
	init();
	int pp=0;
	for(int i=1;i<=m;i++)
	{
		Minn[i]=Minn[i-1]+Z[i];
		int fx=getfa(X[i]),fy=getfa(Y[i]);
		{
			if(fx!=fy)
			{
				fa[fx]=fy;
				fv[fy]+=fv[fx];
				pp+=Z[i];
			}
		}
	}
	int f=1;
	for(int i=1;i<=n;i++)
	{
		if(fv[getfa(i)]!=0)
		{
			f=0;
			break;
		}
	}
	if(!f)
	{
		printf("Impossible\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	ANS=pp;
	init();
	dfs(1,0);
	printf("%d",ANS);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
