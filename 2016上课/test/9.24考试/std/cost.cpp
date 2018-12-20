#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MaxN=20005,MaxM=100005;
struct LinkType
{
	int a,b,c;
};
LinkType w[MaxM],e[MaxM],t[MaxN],q[MaxN],r[MaxN];
int he[MaxM],hq[MaxN],hr[MaxN];
int father[MaxN],mv[MaxN],mark[MaxN];
int ans[MaxN];
int N,M,Q;
int e0=0,q0=0,r0=0;
int GetChar()
{
	char ch;
	int T=0;
	while(ch=getchar())if('0'<=ch&&ch<='9')break;
	for(;'0'<=ch&&ch<='9';ch=getchar())T=T*10+ch-'0';
	return T;
}
void Addq(int x,int y,int z)
{
	q0++; q[q0].a=y; q[q0].b=hq[x]; hq[x]=q0; q[q0].c=z;
}
void Adde(int x,int y,int z)
{
	e0++; e[e0].a=y; e[e0].b=he[x]; he[x]=e0; e[e0].c=z;
}
void Addr(int x,int y)
{
	r0++; r[r0].a=y; r[r0].b=hr[x]; hr[x]=r0;
}
void Read()
{
	int i;
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
	{
		w[i].a=GetChar();
		w[i].b=GetChar();
		w[i].c=GetChar();
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
		t[i].a=GetChar(); t[i].b=GetChar(); 
		Addq(t[i].a,t[i].b,i);
		Addq(t[i].b,t[i].a,i);
	}
}
void Qsort(int L,int R)
{
	int i=L,j=R,Mid=w[(L+R)/2].c;
	while(i<=j)
	{
		while(w[i].c<Mid) i++;
		while(Mid<w[j].c) j--;
		if(i<=j) swap(w[i++],w[j--]);
	}
	if(L<j) Qsort(L,j);
	if(i<R) Qsort(i,R);
}
int Find(int x)
{
	if(father[x]==x) return x;
	int fa=Find(father[x]);
	mv[x]=max(mv[x],mv[father[x]]);
	return father[x]=fa;
}
void Rebuild()
{
	int i,r1,r2;
	for(i=1;i<=N;i++)
		father[i]=i;
	Qsort(1,M);
	for(i=1;i<=M;i++)
	{
		r1=Find(w[i].a);
		r2=Find(w[i].b);
		if(r1!=r2)
		{
			father[r2]=r1; 
			Adde(r1,r2,w[i].c);
			Adde(r2,r1,w[i].c);
		}
	}
}
void Tarjan(int x,int fa)
{
	int i,y,r1,r2;
	father[x]=x; mv[x]=0;
	for(i=he[x];i;i=e[i].b)
	{
		y=e[i].a;
		if(y==fa)continue;
		Tarjan(y,x);
		father[y]=x; mv[y]=e[i].c;
	}
	mark[x]=1;
	for(i=hq[x];i;i=q[i].b)
	{
		y=q[i].a;
		if(mark[y]) Addr(Find(y),q[i].c);
	}
	for(i=hr[x];i;i=r[i].b)
	{
		r1=t[r[i].a].a;
		r2=t[r[i].a].b;
		Find(r1); Find(r2);
		ans[r[i].a]=max(mv[r1],mv[r2]);
	}
}
void Solve()
{
	Rebuild();
	Tarjan(1,0);
	for(int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}
int main()
{   freopen("cost.in","r",stdin);
    freopen("cost.out","w",stdout);
	Read();
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
