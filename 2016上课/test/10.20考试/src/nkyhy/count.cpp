#include<iostream>
#include<cstdio>
#define ll  long long
using namespace std;
const ll mod=1000000007;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ll n,m,i,j,ans=0;
	scanf("%I64d %I64d",&n,&m);
	if(m==1) 
	{
		printf("%I64d",(n*(n-1)*(2*n-1)/6)%mod);
		return 0;
	}
	if(m==2)
	{
		for(i=3;i<=n;i++) ans=(ans+(i-2)*(n-i+1)*(n-i+1))%mod;
		ans=(ans+n*(n-1)*(2*n-1)/6)%mod;
		printf("%I64d",ans);
		return 0;
	}
}
