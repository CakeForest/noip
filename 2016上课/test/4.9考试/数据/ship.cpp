#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=5020;
struct node{
	int s,e;
}city[MAXSIZE];
int n,f[MAXSIZE];
bool cmp(node x,node y)
{
	return x.s<y.s;
}
//f[i]表示从头到i最多能同时允许通过几条航线 
int main()
{
	freopen("ship.in","r",stdin);
	freopen("ship.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&city[i].s,&city[i].e);
	sort(city+1,city+1+n,cmp);
	
	int mmax=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
			if(city[i].e>city[j].e)
				f[i]=max(f[i],f[j]);
		f[i]++;
		mmax=max(f[i],mmax);
	}
	printf("%d",mmax);
	
	return 0;
}
