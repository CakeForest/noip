#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{int u,v,w;}b[200];
int n,m,a[20],ans=0,f[20],al[20],hh[20],sum=0;
int gf(int x){if(f[x]!=x)f[x]=gf(f[x]);return f[x];}
int cmp(const node &a,const node &b){return a.w<b.w;}
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&m);memset(al,0,sizeof(al));
	for(int i=0;i<n;i++)scanf("%d",&a[i]),f[i]=i,sum+=a[i];
	if(sum!=0||(n-1)>m){printf("Impossible\n");return 0;}
	for(int i=1;i<=m;i++)
	{scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(gf(b[i].u)!=gf(b[i].v))
		ans+=b[i].w;
		f[b[i].v]=gf(b[i].u);
	}
	for(int i=0;i<n;i++)
	{int j;
		for(j=1;j<=m;j++)
		{
			if(gf(i)==gf(b[j].u)&&i!=b[j].u)al[i]++,hh[i]=j;
			if(gf(i)==gf(b[j].v)&&i!=b[j].v)al[i]++,hh[i]=j;
		}
		if(al[i]==1&&a[i]==0)ans-=hh[j];
	}
	printf("%d\n",ans);
	return 0;
}
