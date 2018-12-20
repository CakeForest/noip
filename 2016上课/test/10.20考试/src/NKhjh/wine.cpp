#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int red()
{
	int l=0;char m=getchar();bool f=false;
	while(m<'0'||m>'9')
	{
		if(m=='-')f=true;
		m=getchar();
	}
	while(m>='0'&&m<='9')l=(l<<1)+(l<<3)+m-'0',m=getchar();
	if(f)return -l;
	return l;
}
int n,m,a[22],fa[22],ans=0,num[22];
struct node
{
	int x,y,z;
};
node s[200];
int gf(int x)
{
	if(x==fa[x])return x;
	else return fa[x]=gf(fa[x]);
}
bool cmp(node a,node b)
{
	return a.z<b.z;
}
void kruskal()
{
	int i,a,b,faa,fab,l;
	for(i=1;i<=m;i++)
	{
		a=s[i].x;
		b=s[i].y;
		l=s[i].z;
		faa=gf(a);
		fab=gf(b);
		if(faa==fab)continue;
		fa[faa]=fab;
		ans+=l;
	}
}
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	n=red(),m=red();
	int i;
	for(i=1;i<=n;i++)
	a[i]=red();
	for(i=1;i<=m;i++)
	s[i].x=red()+1,s[i].y=red()+1,s[i].z=red();
	for(i=1;i<=n;i++)
	fa[i]=i;
	sort(s+1,s+1+m,cmp);
	kruskal();
	for(i=1;i<=n;i++)
	num[gf(i)]+=a[i];
	for(i=1;i<=n;i++)
	if(num[i]!=0)
	{
	    printf("Impossible");
	    return 0;
	}
	printf("%d",ans);
	return 0;
}
