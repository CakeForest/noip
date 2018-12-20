#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll n,k;
ll haha(ll x)
{
	return x*(2*x+1)*(x+1)/6%mod;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ll i,ans=0;
	scanf("%I64d%I64d",&n,&k);
	if(n==1)
	{
	    printf("0");
	    return 0;
	}
	else if(n==2)
	{
		printf("1");
		return 0;
	}
	if(k==1)
	{
		n--;
		ans=n*(2*n+1)*(n+1)/6%mod;
	    printf("%I64d",ans);
	}
	else if(k==2)
	{
		ans=1;
		for(i=4;i<=n;i++)
		ans=(ans+haha(i-2))%mod;
		printf("%I64d",ans+haha(n-1));
	}
	return 0;
}
