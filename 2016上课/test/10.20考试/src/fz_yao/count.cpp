#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int mod=1000000007;
long long f[100001],g[100001],b[100001],a[100001];
int n,k;
int main()
{
	int i,j;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&k);
	f[2]=1;
	for(i=3;i<=n;i++) 
	f[i]=(((i-1)*(i-1))%mod+f[i-1]%mod)%mod;	
	if(k==2)
	{
		for(i=1;i<=n-1;i++)
		{
			for(j=i;j<=n-i;j++)
			{
				if(i!=j)
				g[n]=(g[n]+(((n-i)/j*(n-j)/i)*2)%mod)%mod;
				else
				g[n]=(g[n]+(n-i)*(n-i)%mod)%mod;
			}
		}
	}

	if(k==1)
	printf("%lld",f[n]%mod);
	if(k==2)
	printf("%lld",(f[n]+g[n])%mod);
	
	return 0;
}
