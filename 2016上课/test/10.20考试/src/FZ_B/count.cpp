#include<cstdio>
#define inf 1000000007
long long n,k,ans=0;
long long count1(long long a)
{
	if(a==n-1) return 1;
	long long tmp=n-a;
	tmp*=tmp;
	return tmp+count1(a+1);
}
long long count2()
{
	long long tmp=0;
	long long i,j;
	for(i=2;i<=n-1;i++)
	for(j=2;j<=n-1,n-j>=i-1;j++)
	{
		//if(i==j) continue;//later
		long long mult=n-i-j+2;
		mult*=mult;
		tmp+=mult;
	}
	return tmp;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	ans+=count1(1);
	if(k==2) ans+=count2();
	printf("%lld",ans%inf);
	return 0;
}
