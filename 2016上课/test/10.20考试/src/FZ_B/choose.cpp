#include<cstdio>
#include<climits>
#include<cstdlib>
#define MAXN 200010
long long n,m,a[MAXN];
long long ans=LLONG_MIN;
bool exist[MAXN];
bool ifnext(int k)
{
	int h=k-1,t=k+1;
	if(h==0) h=n;
	if(t>n) t=1;
	if(exist[h]||exist[t]) return true;
	else return false;
}

void outline(int k)//for test only
{
	//exist[k]=true;
	for(int i=1;i<=n;i++) printf("%d ",exist[i]);
	puts("");
	printf("%lld chose.\n",a[k]);
	system("pause");
	return;
}
long long dig(long long k)
{
	if(k>m) return 0;
	long long max=LLONG_MIN;
	for(int i=1;i<=n;i++)
	{
		if(exist[i]==false && ifnext(i)==false)
		{
			exist[i]=true;
			//outline(i);
			long long tmp=a[i]+dig(k+1);
			exist[i]=false;
			if(tmp>max) max=tmp;
		}
		//else printf("%d choice failure.\n",i);
	}
	return max;
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int i,j;
	scanf("%lld %lld",&n,&m);
	if(m>n/2)
	{
		printf("Error!");
		return 0;
	}
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	ans=dig(1);
	printf("%lld",ans);
}
