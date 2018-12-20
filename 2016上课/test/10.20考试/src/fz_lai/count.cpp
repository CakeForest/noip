#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long ans=(n-1)*n*(2*n-1)/6%mod;
	if(k==1) printf("%lld\n",ans);//printf("%lld",(n-1)*n*(2*n-1)/6%mod);
	else
	{
		for(long long i=n;i>=3;i--)
		{
			ans+=(i-2)*(n-i+1)%mod*(n-i+1);
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
