#include<cstdio>
const int mod=1000000007;
int n,k;
int setup()
{
	scanf("%d %d",&n,&k);
	return k;
}
void pro1()
{
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=(n-i)*(n-i)%mod;
		ans%=mod;
	}
	printf("%d",ans);
}
void pro2()
{
	long long ans=(n-1)*(n-1)%mod;
	for(int i=2;i<n;i++)
	{
		ans+=(n-i)*(n-i)*i%mod;
		ans%=mod;
	}
	printf("%lld",ans);
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	if(setup()==1)
		pro1();
	else
		pro2();
	return 0;
}
